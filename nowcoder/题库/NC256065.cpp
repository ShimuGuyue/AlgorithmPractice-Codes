#include <iostream>
#include <string>

int main(void)
{
    std::string s;
    std::cin >> s;
    for (char& c : s)
    {
        if (isupper(c))
            if (c == 'Z')
                c = 'A';
            else
                ++c;
        else if (islower(c))
            if (c == 'a')
                c = 'z';
            else
                --c;
    }
    std::cout << s << std::endl;
    return 0;
}