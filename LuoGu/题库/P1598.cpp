#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> letters(26);
    int max(0);
    for (int i(0); i < 4; ++i)
    {
        std::string s;
        std::getline(std::cin, s);
        for (char c : s)
        {
            if (isalpha(c))
            {
                ++letters[c - 'A'];
                max = std::max(max, letters[c - 'A']);
            }
        }
    }
    for (int i(max); i > 0; --i)
    {
        int index(0);
        for (int j(0); j < 26; ++j)
        {
            if (letters[j] >= i)
                index = j;
        }
        for (int j(0); j < index; ++j)
        {
            if (letters[j] >= i)
                std::cout << "* ";
            else
                std::cout << "  ";
        }
        std::cout << "*" << std::endl;
    }
    for (char c('A'); c < 'Z'; ++c)
    {
        std::cout << c << " ";
    }
    std::cout << "Z" << std::endl;
    return 0;
}