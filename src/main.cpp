#include "utils.hpp"
#include "imageWizardry.hpp"
#include <filesystem>
#include <string>

int main(int argc, char** argv )
{
    std::string path;
    if (argc > 1)
    {
        path = std::filesystem::absolute(argv[1]).string();
    }
    else
    {
        path = std::filesystem::current_path().string();
    }

    bool scale;
    if (argc > 2)
    {
        scale = std::string(argv[2]) != "false";
    }
    else 
    {
        scale = true;
    }
    imageWizardry magic = imageWizardry(scale);
    magic.splitThis(path);

    std::cout << "Done!\n";
    return 0;
}