#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include "Reader.h"

int main()
{
    int opt;
    std::cout << "Hello and welcome!\nPlease pick a option:\n";
   while (true)
   {
        std::cout <<"1) Show all files\n2) Copy file\n"
        "3) Comment file\n4) Fix blanks\n5) Fix indent"
        "\n6) Fix dots\n10) Quit\n";
        std::cin >> opt;
        if (opt == 1)
        {
            std::string path = std::filesystem::current_path();
            
            
            for (const auto & file : std::filesystem::directory_iterator(path))
            std::cout << file.path() << std::endl;

            std::cout << "\n\n";
        }
        else if(opt == 2)
        {
            std::cout << "File to copy:";
            std::string fileName;
            std::cin >> fileName;
            if (std::filesystem::exists(fileName))
            {
                Reader Readfile(fileName);
                Readfile.CopyFile(fileName);
                std:: cout << "Done!\nNew file name: new" + fileName + "\n\n"<< std::endl;
            }
            else 
            {
                std::cout << "That file does not exist!\n\n";
            }
        }
          else if(opt == 3)
        {
            std::cout << "File to fix comments:";
            std::string fileName;
            std::cin >> fileName;
            if (std::filesystem::exists(fileName))
            {
                Reader Readfile(fileName);
                Readfile.formatcomment(fileName);
            }
            else 
            {
                std::cout << "That file does not exist!\n\n";
            }
        }
        else if(opt == 4)
        {
            std::cout << "File to fix blanks:";
            std::string fileName;
            std::cin >> fileName;
            if (std::filesystem::exists(fileName))
            {
                Reader Readfile(fileName);
                Readfile.blankSections(fileName);
            }
            else 
            {
                std::cout << "That file does not exist!\n\n";
            }
        }
        else if(opt == 5)
        {
            std::cout << "File to fix indent:";
            std::string fileName;
            std::cin >> fileName;
            if (std::filesystem::exists(fileName))
            {
                Reader Readfile(fileName);
                Readfile.indent(fileName);
            }
            else 
            {
                std::cout << "That file does not exist!\n\n";
            }
        }
        else if(opt == 6)
        {
            std::cout << "File to newline:";
            std::string fileName;
            std::cin >> fileName;
            if (std::filesystem::exists(fileName))
            {
                Reader Readfile(fileName);
                Readfile.newlineFix(fileName);
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