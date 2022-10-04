#include "Reader.h"

Reader::Reader(std::string& file)
{
    //std::ofstream newfile(file);
    //newfile.close();
}



void Reader::CopyFile(std::string file)
{
    std::ifstream src(file, std::ios::binary);
    std::ofstream dst("new" + file, std::ios::binary);
    dst << src.rdbuf();
}


void Reader::formatcomment(std::string file)
{
    std::ifstream src(file, std::ios::binary);
    std::ofstream dst("new" + file, std::ios::binary);
    for (std::string line; getline(src,line);)
    {
        
        if (line[0] == '%')
        {
            line.erase(0,1);
            line.insert(0,"% ");
            dst << line + "\n";
        }
        else 
        {
            dst << line + "\n";
        }
    }
}

//fix number adjutstable
void Reader::blankSections(std::string file)
{
    std::ifstream src(file, std::ios::binary);
    std::ofstream dst("new" + file, std::ios::binary);
    std::string words[3] = {"\\subsection","\\section","\\chapter"};
    int arrayLength = sizeof(words)/sizeof(std::string);
    for (std::string line; getline(src,line);)
    {
       for (int i = 0; i < arrayLength; i++)
       {
        if (line.find(words[i]) != std::string::npos)
        {
            line.insert(0,"\n");
            dst << line + "\n";
            break;
        }
        if (i == arrayLength-1)
        {
            dst << line + "\n";
        }
       }
    }
}

void Reader::indent(std::string file)
{
    std::ifstream src(file, std::ios::binary);
    std::ofstream dst("new" + file, std::ios::binary);
    int beginCount = 0;
    std::string indent = "    ";
    
    for (std::string line; getline(src,line);)
    {
        std::string indentString(beginCount,'\t');
        //Use && instead of new if statement
        if (line.find("\\begin{") != std::string::npos)
        {
           if(line.find("\\begin{document}") == std::string::npos)
           {
                dst << indentString + line + "\n";
                beginCount++;
                continue;;
           }
            
        }
        //Maybe else if???
        if (line.find("\\end{") != std::string::npos)
        {
            //Use && instead of new if statement
            if(line.find("\\end{document}") == std::string::npos)
           {
                beginCount--;
                std::string indentString(beginCount,'\t');
                dst << indentString + line + "\n";
                continue;;
           }
        }
        dst << indentString + line + "\n";
    }
}

void Reader::newlineFix(std::string file)
{
    std::ifstream src(file, std::ios::binary);
    std::ofstream dst("new" + file, std::ios::binary);
    for (std::string line; getline(src,line);)
    {
        std::vector<int> dotPositions;
        size_t pos = line.find(".", 0);
        while (pos != std::string::npos)
        {
            dotPositions.push_back(pos);
            pos = line.find(".", pos+1);
        }

        for (int i = 0; i < dotPositions.size(); i++)
        {
            line.replace(dotPositions[i],dotPositions[i], ".\n");
        }
        dst << line + "\n";

    }
}

//För korrektion med samtliga delar en funktion med olika checks