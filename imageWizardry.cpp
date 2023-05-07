#include "imageWizardry.hpp"

imageWizardry::imageWizardry(bool scaleImage)
{
    this->scale = scaleImage;
}

void imageWizardry::splitFrame()
{
    int y = 0;
    for (int i = 1; i <= this->rows; i++) 
    {
        int x = 0;
        for (int j = 1; j <= this->columns; j++)
        {
            cv::Mat cropImg = this->image(cv::Rect(x, y, this->columnsSize, this->rowsSize));
            if (this->scale) cv::resize(cropImg, cropImg, blockSize);

            x += columnsSize;

            cv::imwrite(this->outputFolder + "/" + utils::cutOffExtension(filename) + "_" + utils::intToStr(i) + "_" + utils::intToStr(j) + ".png", cropImg);
        }

        y += rowsSize;
    }
}

void imageWizardry::inputLoop(std::string dimensionName, int &dimension, int &size, int dimRestrictor)
{
    std::string input;

    while (dimension <= 0)
    {
        std::cout << "Enter number of " + dimensionName + " blocks to split into. Defaults to approximately 48px width. Must be greater than 0 and not greater than the amount of pixels for the width. ";
        std::getline(std::cin, input);
        if (input.empty())
        {
            dimension = dimRestrictor / 48;
            size = 48;
        }
        else
        {
            try
            {
                dimension = utils::parseInt(input);
            }
            catch (std::exception e)
            {
                dimension = 0;
            }

            if (dimension > dimRestrictor)
            {
                dimension = 0;
                continue;
            }

            size = dimRestrictor / dimension;
        }
    }
}

void imageWizardry::loopThroughDir(std::string dir)
{
    this->workingDirectory = dir;

    DIR *dp = nullptr;
    struct dirent *entry = nullptr;
    dp = opendir(this->workingDirectory.c_str());

    while ((entry = readdir(dp)))
    {
        //d_type 8 means file, 4 means directory
        if ((int)(entry->d_type) == 8 && (utils::hasImageExtension(entry->d_name)))
        {
            this->image = cv::imread(this->workingDirectory + "/" + entry->d_name);

            if (image.data)
            {
                this->filename = entry->d_name;
                this->outputFolder = this->workingDirectory + "/" + utils::cutOffExtension(this->filename);
                std::cout << "Found " << entry->d_name << " (" << this->image.size().width << "x" << this->image.size().height << "px)\n";
                if (std::filesystem::directory_entry(this->outputFolder).exists())
                {
                    std::string option;
                    std::cout << "Output folder already exists, skip? [Y/n] ";
                    std::getline(std::cin, option);
                    if (option.empty() || (option[0] != 'n' && option[0] != 'N'))
                    {
                        std::cout << "\n";
                        continue;
                    }
                }

                this->columns = 0; this->rows = 0; this->columnsSize = 48; this->rowsSize = 48;
                std::string columnsInput, rowsInput;
                
                inputLoop("column", this->columns, this->columnsSize, image.size().width);
                inputLoop("row", this->rows, this->rowsSize, image.size().height);

                std::cout << "Splitting into " << (scale ? "scaled " : "") << this->columns << "x" << this->rows << " blocks with " << (scale ? "initial " : "") << "sizes of " << this->columnsSize << "x" << this->rowsSize << "px\n";
                
                int averageDimension = (columnsSize + rowsSize) / 2;
                this->blockSize = cv::Size(averageDimension, averageDimension);
                mkdir(this->outputFolder.c_str(), S_IRWXU + S_IRWXG + S_IRWXO);
                splitFrame();
                std::cout << "\n";
            }
        }
    }


    closedir(dp);
}

