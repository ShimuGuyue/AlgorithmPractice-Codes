#include <iostream>

int main(void)
{
    std::string s;
    std::cin >> s;
    for (char& c : s)
    {
        if (isalpha(c))
            c = toupper(c);
    }
    std::cout << s << std::endl;
    return 0;
}