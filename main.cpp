#include "libraries/json.hpp"
#include "Reader.h"

using json = nlohmann::json;
int main()
{

    if (!std::filesystem::exists("rules.json"))
    {
        json j = "{\"rules\":[{\"rule_name\":\"intentions\",\"active\":true},{\"rule_name\":\"newline\",\"active\":true},{\"rule_name\":\"format_comment\",\"active\":true},{\"rule_name\":\"blank_lines\",\"active\":true,\"number\":1}]}"_json;
        std::ofstream rules("rules.json", std::ios::binary);
        rules << j;
    }
    std::ifstream f("rules.json");
    json data = json::parse(f);
    bool intentionsRule = data.at("rules")[0].at("active");
    bool newlineRule = data.at("rules")[1].at("active");
    bool formatCommentRule = data.at("rules")[2].at("active");
    bool blankLineRule = data.at("rules")[3].at("active");
    int blankLineRuleInt = data.at("rules")[3].at("number");
    std::cout << "Hello and welcome!\nPlease pick a option:\n";
    while (true)
    {
        std::string opt;
        std::cout << "1) Show all files\n2) Copy file\n"
                     "3) Apply rules\n10) Quit\n";
        std::cin >> opt;
        if (opt == "1")
        {
            std::string path = std::filesystem::current_path();
            for (const auto &file : std::filesystem::directory_iterator(path))
                std::cout << file.path() << std::endl;
            std::cout << "\n\n";
        }
        else if (opt == "2")
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
        else if (opt == "3")
        {
            std::cout << "Fix all rules to file:";
            std::string fileName;
            std::cin >> fileName;
            if (std::filesystem::exists(fileName))
            {
                Reader Readfile;
                auto start = std::chrono::high_resolution_clock::now();
                Readfile.allRules(fileName, intentionsRule, newlineRule, formatCommentRule, blankLineRule, blankLineRuleInt);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                std::cout << std::to_string(duration.count()) + " microseconds" << std::endl;
            }
            else
            {
                std::cout << "That file does not exist!\n\n";
            }
        }
        else if (opt == "10")
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