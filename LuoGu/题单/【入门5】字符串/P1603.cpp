#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main(void)
{
    std::map<std::string, int> digits;
    digits["one"]   =  1; digits["eleven"]    = 11; digits["a"]       = 1;
    digits["two"]   =  2; digits["twelve"]    = 12; digits["both"]    = 2;
    digits["three"] =  3; digits["thirteen"]  = 13; digits["another"] = 1;
    digits["four"]  =  4; digits["fourteen"]  = 14; digits["first"]   = 1;
    digits["five"]  =  5; digits["fifteen"]   = 15; digits["second"]  = 2;
    digits["six"]   =  6; digits["sixteen"]   = 16; digits["third"]   = 3;
    digits["seven"] =  7; digits["seventeen"] = 17;
    digits["eight"] =  8; digits["eighteen"]  = 18;
    digits["nine"]  =  9; digits["nineteen"]  = 19;
    digits["ten"]   = 10; digits["twenty"]    = 20;

    std::vector<int> anss;
    for (int i(0); i < 6; ++i)
    {
        std::string s;
        std::cin >> s;
        int digit(digits[s]);
        if (digit == 0)
            continue;
        digit = digit * digit % 100;
        if (digit == 0)
            continue;
        anss.push_back(digit);
    }
    
    if (anss.size() == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::sort(anss.begin(), anss.end());
    std::cout << anss.front();
    for (int i(1); i < anss.size(); ++i)
    {
        if (anss[i] < 10)
            std::cout << 0;
        std::cout << anss[i];
    }
    std::cout << std::endl;
    return 0;
}