#include <string>
#include <iostream>
#include <filesystem>
//#include "libraries/json.hpp"
#include "Reader.h"

// using json = nlohmann::json;

int main()
{
    int opt;
    std::cout << "Hello and welcome!\nPlease pick a option:\n";
    while (true)
    {
        std::cout << "1) Show all files\n2) Copy file\n"
                     "3) Apply rules\n10) Quit\n";
        std::cin >> opt;
        if (opt == 1)
        {
            std::string path = std::filesystem::current_path();
            for (const auto &file : std::filesystem::directory_iterator(path))
                std::cout << file.path() << std::endl;
            std::cout << "\n\n";
        }
        else if (opt == 2)
        {
            std::cout << "File to copy:";
            std::string fileName;
            std::cin >> fileName;
            if (std::filesystem::exists(fileName))
            {
                Reader Readfile;
                Readfile.CopyFile(fileName);
                std::cout << "Done!\nNew file name: new" + fileName + "\n\n"
                          << std::endl;
            }
            else
            {
                std::cout << "That file does not exist!\n\n";
            }
        }
        else if (opt == 3)
        {
            std::cout << "Fix all rules to file:";
            std::string fileName;
            std::cin >> fileName;
            if (std::filesystem::exists(fileName))
            {
                Reader Readfile;
                Readfile.allRules(fileName, true, true, true, true, 1);
            }
            else
            {
                std::cout << "That file does not exist!\n\n";
            }
        }
        else if (opt == 10)
        {
            break;
        }
        else
        {
            std::cout << "that is not an option!\n\n";
        }
    }
    return 1;
}