#include "utils.hpp"
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <sys/stat.h>
#include <dirent.h>
#include <exception>
#pragma once

class imageWizardry
{
public:
    void splitFrame();
    void loopThroughDir(std::string);
    imageWizardry(bool);

private:
    cv::Mat image;
    std::string outputFolder;
    int rows;
    int rowsSize;
    int columns;
    int columnsSize;
    bool scale;
    std::string filename;
    cv::Size blockSize;
    std::string workingDirectory;
    void inputLoop(std::string, int&, int&, int);
};