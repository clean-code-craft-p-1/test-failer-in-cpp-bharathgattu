#include <iostream>
#include <assert.h>

int getPairNumber(int majorColId,int minorColorId)
{
    return majorColId * 5 + minorColorId+1;
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << getPairNumber(i,j) << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    return i * j;
}

namespace testPrintColorMap_stub
{
    void testPrintColorMap()
    {
        int result = printColorMap();
        assert(getPairNumber(0, 1) == 2);
        assert(getPairNumber(0, 4) == 5);
        assert(getPairNumber(4, 4) == 25);
        assert(result == 25);
        std::cout << "All is well (maybe!)\n";
    }
}

int main() {
    testPrintColorMap_stub::testPrintColorMap();
    return 0;
}