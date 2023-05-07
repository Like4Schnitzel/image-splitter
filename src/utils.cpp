#include "utils.hpp"

bool utils::strEndsWith(std::string str, std::string ending)
{
    const int endingSize = ending.size();
    const int stringSize = str.size();

    if (endingSize > stringSize)
        return false;

    for (int i = 1; i <= endingSize; i++)
    {
        if (str[stringSize - i] != ending[endingSize - i])
            return false;
    }

    return true;
}

bool utils::hasImageExtension(std::string filename)
{
    std::string supportedExtensions[] = {".png", ".jpg", ".jpeg", ".webp"};

    for (std::string str : supportedExtensions)
    {
        if (utils::strEndsWith(filename, str))
            return true;
    }

    return false;
}

std::string utils::cutOffExtension(std::string filename)
{
    //find position of final period
    int periodPosition;
    for (periodPosition = filename.size() - 1; filename[periodPosition] != '.'; periodPosition--);

    std::string filenameWithoutExtension = "";
    for (int i = 0; i < periodPosition; i++)
    {
        filenameWithoutExtension += filename[i];
    }

    return filenameWithoutExtension;
}

int utils::parseInt(std::string str)
{
    int multiplier = 1;
    int parsedInt = 0;

    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }

        parsedInt += (str[i] - '0') * multiplier;
        multiplier *= 10;
    }
    
    return parsedInt;
}

std::string utils::intToStr(int n)
{
    if (n == 0)
    {
        return "0";
    }

    std::string str = "";
    while (n > 0)
    {
        str = (char)(n % 10 + '0') + str;
        n /= 10;
    }
    return str;
}