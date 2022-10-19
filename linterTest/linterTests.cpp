#include "../Reader.h"
#include <gtest/gtest.h>
#include "../Reader.cpp"

TEST(ReaderTest, formatComment)
{
    Reader r1;
    std::string testComment1 = "%hello";
    std::string testComment2 = "%           hello";
    std::string testComment3 = "%  hello";
    std::string testComment4 = "% hello";
    std::string expectedComment = "% hello";
    r1.formatcomment(testComment1);
    r1.formatcomment(testComment2);
    r1.formatcomment(testComment3);
    r1.formatcomment(testComment4);
    EXPECT_EQ(
        expectedComment,
        testComment1);
    EXPECT_EQ(
        expectedComment,
        testComment2);
    EXPECT_EQ(
        expectedComment,
        testComment3);
    EXPECT_EQ(
        expectedComment,
        testComment4);
}

TEST(ReaderTest, blankSections)
{
    Reader r1;
    std::string testSection1 = "\\section{Introduction}";
    std::string expectedSection1 = "\n\\section{Introduction}";
    std::string testSection2 = "\\section{Introduction}";
    std::string expectedSection2 = "\n\n\\section{Introduction}";
    r1.blankSections(testSection1, 1);
    r1.blankSections(testSection2, 2);
    EXPECT_EQ(
        testSection1,
        expectedSection1);
    EXPECT_EQ(
        testSection2,
        expectedSection2);
}

TEST(ReaderTest, indent)
{
    Reader r1;
    int count1 = 1;
    std::string testIndent1 = "Test Test Test Test";
    std::string expectedIndent1 = "\tTest Test Test Test";
    r1.indent(testIndent1, count1);
    EXPECT_EQ(
        testIndent1,
        expectedIndent1);
}

TEST(ReaderTest, newlineFix)
{
    Reader r1;
    std::string testNewline1 = "More Tests and more. ";
    std::string expectedNewline1 = "More Tests and more.\n";
    r1.newlineFix(testNewline1);
    EXPECT_EQ(
        testNewline1,
        expectedNewline1);
}
