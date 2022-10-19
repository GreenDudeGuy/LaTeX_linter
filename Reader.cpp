#include "Reader.h"

Reader::Reader()
{
    // std::ofstream newfile(file);
    // newfile.close();
}

void Reader::CopyFile(std::string file)
{
    std::ifstream src(file, std::ios::binary);
    std::ofstream dst("new" + file, std::ios::binary);
    dst << src.rdbuf();
}

void Reader::formatcomment(std::string &line)
{
    if (line[0] == '%')
    {
        char notBlank;
        int count = 1;
        for (int i = 1; i < line.size(); i++)
        {
            if (line[i] != ' ')
            {
                break;
            }
            count++;
        }
        line.erase(0, count);
        line.insert(0, "% ");
    }
}

void Reader::blankSections(std::string &line, int blanklines)
{
    std::string words[6] = {"\\subsection", "\\section", "\\chapter", "\\paragraph", "\\subparagraph", "\\part"};
    int arrayLength = sizeof(words) / sizeof(std::string);
    std::string blankline;
    for (int i = 0; i < blanklines; i++)
    {
        blankline += "\n";
    }
    for (int i = 0; i < arrayLength; i++)
    {
        if (line.find(words[i]) != std::string::npos)
        {
            line.insert(0, blankline);
            line + "\n";
            break;
        }
        if (i == arrayLength - 1)
        {
            line + "\n";
        }
    }
}

void Reader::indent(std::string &line, int &beginCount)
{
    std::string indent = "";
    if (line.find("\\begin{") != std::string::npos)
    {
        if (line.find("\\begin{document}") == std::string::npos)
        {
            for (int i = 0; i < beginCount; i++)
            {
                indent += "\t";
            }
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] != ' ')
                {
                    line.replace(0, i, indent);
                    break;
                }
            }
            beginCount++;
        }
    }
    else if (line.find("\\end{") != std::string::npos)
    {
        if (line.find("\\end{document}") == std::string::npos)
        {
            beginCount--;
            for (int i = 0; i < beginCount; i++)
            {
                indent += "\t";
            }
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] != ' ')
                {
                    line.replace(0, i, indent);
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < beginCount; i++)
        {
            indent += "\t";
        }
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] != ' ')
            {
                line.replace(0, i, indent);
                break;
            }
        }
    }
}

void Reader::newlineFix(std::string &line)
{
    std::string dots = ". ";
    std::string dotsNewline = ".\n";
    std::vector<std::pair<std::string, int>> links;
    size_t posLink = std::string::npos;
    if (line[0] == '%' || line[0] == '\\')
    {
        line + "\n";
    }
    else
    {
        size_t pos = line.find(dots);
        while (pos != std::string::npos)
        {
            line.replace(pos, dots.size(), dotsNewline);
            pos = line.find(dots, pos + dotsNewline.size());
        }
        line + "\n";
    }
}

void Reader::allRules(std::string file, bool intentions, bool newline, bool formatComments, bool blank_lines, int number)
{
    std::ifstream src(file, std::ios::binary);
    std::ofstream dst("new" + file, std::ios::binary);
    int beginCount = 0;
    for (std::string line; getline(src, line);)
    {
        if (formatComments)
        {
            formatcomment(line);
        }
        if (blank_lines)
        {
            blankSections(line, number);
        }
        if (newline)
        {
            newlineFix(line);
        }
        if (intentions)
        {
            indent(line, beginCount);
        }
        dst << line + "\n";
    }
}
