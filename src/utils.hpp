#include <iostream>
#pragma once

class utils
{
public:
    static bool strEndsWith(std::string, std::string);
    static bool hasImageExtension(std::string);
    static std::string cutOffExtension(std::string);
    static int parseInt(std::string);
    static std::string intToStr(int);
};