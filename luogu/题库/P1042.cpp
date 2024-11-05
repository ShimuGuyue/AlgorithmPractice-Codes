#include <iostream>

int main(void)
{
    std::string s;
    while (1)
    {
        std::string temp;
        std::cin >> temp;
        bool go(true);
        for (char c : temp)
        {
            if (c != 'E')
                s += c;
            else
            {
                go = false;
                break;
            }
        }
        if (!go)
            break;
    }

    if (s.empty())
    {
        std::cout << "0:0" << std::endl;
        std::cout << std::endl;
        std::cout << "0:0" << std::endl;
        return 0;
    }

    {
        int positive(0);
        int negative(0);
        for (char c : s)
        {
            if (c == 'W')
                ++positive;
            else if (c == 'L')
                ++negative;

            if ((positive >= 11 || negative >= 11) && abs(positive - negative) >= 2)
            {
                std::cout << positive << ":" << negative << std::endl;
                positive = 0;
                negative = 0;
            }
        }
        std::cout << positive << ":" << negative << std::endl;
    }
    std::cout << std::endl;
    {
        int positive(0);
        int negative(0);
        for (char c : s)
        {
            if (c == 'W')
                ++positive;
            else if (c == 'L')
                ++negative;

            if ((positive >= 21 || negative >= 21) && abs(positive - negative) >= 2)
            {
                std::cout << positive << ":" << negative << std::endl;
                positive = 0;
                negative = 0;
            }
        }
        std::cout << positive << ":" << negative << std::endl;
    }
    return 0;
}