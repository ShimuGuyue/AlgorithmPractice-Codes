#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;

    std::string s;
    for (int i(0); i < n; ++i)
    {
        s += "o";
    }
    for (int i(0); i < n; ++i)
    {
        s += "*";
    }
    s += "--";
    std::cout << s << std::endl;

    for (int i(n); i > 4; --i)
    {
        std::swap(s[i-1], s[i*2]);
        std::swap(s[i], s[i*2+1]);
        std::cout << s << std::endl;

        std::swap(s[i-1], s[(i-1)*2]);
        std::swap(s[i], s[(i-1)*2+1]);
        std::cout << s << std::endl;
    }

    std::cout << "ooo--***";
    for (int i(3); i < n; ++i)
    {
        std::cout << "o*";
    }
    std::cout << std::endl;

    std::cout << "ooo*o**--*";
    for (int i(4); i < n; ++i)
    {
        std::cout << "o*";
    }
    std::cout << std::endl;

    std::cout << "o--*o**o";
    for (int i(3); i < n; ++i)
    {
        std::cout << "o*";
    }
    std::cout << std::endl;

    std::cout << "o*o*o*--";
    for (int i(3); i < n; ++i)
    {
        std::cout << "o*";
    }
    std::cout << std::endl;

    std::cout << "--";
    for (int i(0); i < n; ++i)
    {
        std::cout << "o*";
    }
    std::cout << std::endl;

    return 0;
}

/*
ooooooo*******--

oooooo--******o*
oooooo******--o*
ooooo--*****o*o*
ooooo*****--o*o*
oooo--****o*o*o*
oooo****--o*o*o*

ooo--***o*o*o*o*
ooo*o**--*o*o*o*#
o--*o**oo*o*o*o*#
o*o*o*--o*o*o*o*#
--o*o*o*o*o*o*o*#
 */