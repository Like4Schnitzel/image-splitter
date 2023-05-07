#include <iostream>
#pragma once

class utils
{
public:
    static bool strEndsWith(std::string str, std::string ending);
    static bool hasImageExtension(std::string filename);
    static std::string cutOffExtension(std::string filename);
    static int parseInt(std::string str);
    static std::string intToStr(int n);
};