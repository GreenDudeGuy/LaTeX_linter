#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <gflags/gflags.h>



class Reader
{
public:
    Reader(std::string& file);
    void CopyFile(std::string file);
    void formatcomment(std::string file);
    void blankSections(std::string file);
    void indent(std::string file);
    void newlineFix(std::string file);
private:

};