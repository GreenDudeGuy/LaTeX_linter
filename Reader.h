#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <chrono>

class Reader
{
public:
    Reader(void);
    void CopyFile(std::string file);
    void formatcomment(std::string &line);
    void blankSections(std::string &line, int blanklines);
    void indent(std::string &line, int &beginCount);
    void newlineFix(std::string &line);
    void allRules(std::string file, bool intentions, bool newline, bool formatComments, bool blank_lines, int number = 0);

private:
};
