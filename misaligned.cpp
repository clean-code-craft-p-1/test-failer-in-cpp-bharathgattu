#include <iostream>
#include <assert.h>
#include<iomanip>
#include<vector>
#include<sstream>

int getPairNumber(int majorColId,int minorColorId)
{
    return majorColId * 5 + minorColorId+1;
}

void fillExpectedColorMap(std::vector<std::string>& expectedColorMap)
{
        expectedColorMap.push_back("  1 |  White | Blue\n");
        expectedColorMap.push_back("  2 |  White | Orange\n");
        expectedColorMap.push_back("  3 |  White | Green\n");
        expectedColorMap.push_back("  4 |  White | Brown\n");
        expectedColorMap.push_back("  5 |  White | Slate\n");
        expectedColorMap.push_back("  6 |    Red | Blue\n");
        expectedColorMap.push_back("  7 |    Red | Orange\n"); 
        expectedColorMap.push_back("  8 |    Red | Green\n");
        expectedColorMap.push_back("  9 |    Red | Brown\n");
        expectedColorMap.push_back(" 10 |    Red | Slate\n");
        expectedColorMap.push_back(" 11 |  Black | Blue\n");
        expectedColorMap.push_back(" 12 |  Black | Orange\n");
        expectedColorMap.push_back(" 13 |  Black | Green\n"); 
        expectedColorMap.push_back(" 14 |  Black | Brown\n");
        expectedColorMap.push_back(" 15 |  Black | Slate\n");
        expectedColorMap.push_back(" 16 | Yellow | Blue\n");
        expectedColorMap.push_back(" 17 | Yellow | Orange\n");
        expectedColorMap.push_back(" 18 | Yellow | Green\n");
        expectedColorMap.push_back(" 19 | Yellow | Brown\n");
        expectedColorMap.push_back(" 20 | Yellow | Slate\n");
        expectedColorMap.push_back(" 21 | Violet | Blue\n");
        expectedColorMap.push_back(" 22 | Violet | Orange\n");
        expectedColorMap.push_back(" 23 | Violet | Green\n");
        expectedColorMap.push_back(" 24 | Violet | Brown\n");
        expectedColorMap.push_back(" 25 | Violet | Slate\n");
}

int printColorMap(std::vector<std::string>& printedColorMap) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::stringstream buffer;
            std::string tempStr;
            std::cout << std::setw(3) << getPairNumber(i,j) << std::setw(3) << " | " << std::setw(6) << majorColor[i] << " | " << std::setw(3) << minorColor[j] << "\n";
            buffer << std::setw(3) << getPairNumber(i, j) << std::setw(3) << " | " << std::setw(6) << majorColor[i] << " | " << std::setw(3) << minorColor[j] << "\n";
            tempStr = buffer.str();
            printedColorMap.push_back(tempStr);
        }
    }
    return i * j;
}

namespace testPrintColorMap_stub
{
    bool isColorMapAligned(std::vector<std::string>& printedColorMap)
    {
        std::vector<std::string> expectedColorMap;
        fillExpectedColorMap(expectedColorMap);
        for (auto i : expectedColorMap)
            std::cout << i;

        if (expectedColorMap == printedColorMap)
        {
            std::cout << "Alignment is Good" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Bad alignment in colorMap" << std::endl;
            return false;
        }

    }
    void testPrintColorMap()
    {
        std::vector<std::string> printedColorMap;
        int result = printColorMap(printedColorMap);
        assert(result == 25);
        assert(isColorMapAligned(printedColorMap) == true);
        
        assert(getPairNumber(0, 1) == 2);
        assert(getPairNumber(0, 4) == 5);
        assert(getPairNumber(4, 4) == 25);

        std::cout << "All is well (maybe!)\n";
    }
}

int main() {
    testPrintColorMap_stub::testPrintColorMap();
    return 0;
}