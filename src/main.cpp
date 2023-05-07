#include "utils.hpp"
#include "imageWizardry.hpp"
#include <string>

int main(int argc, char** argv )
{
    bool scale = argc > 2 ? !(std::string(argv[2]) == "false") : true;
    std::string currentDirectory = (argc > 1 ? argv[1] : std::filesystem::current_path().string());

    imageWizardry magic = imageWizardry(scale);
    magic.loopThroughDir(currentDirectory);

    std::cout << "Done!\n";
    return 0;
}