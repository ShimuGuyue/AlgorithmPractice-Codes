#include <iostream>

std::string flags[5][10]{
    "XXX", "..X", "XXX", "XXX", "X.X", "XXX", "XXX", "XXX", "XXX", "XXX",
    "X.X", "..X", "..X", "..X", "X.X", "X..", "X..", "..X", "X.X", "X.X",
    "X.X", "..X", "XXX", "XXX", "XXX", "XXX", "XXX", "..X", "XXX", "XXX",
    "X.X", "..X", "X..", "..X", "..X", "..X", "X.X", "..X", "X.X", "..X",
    "XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX"
};

int main(void)
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    for (int i(0); i < 5; ++i)
    {
        for (int j(0); j < n - 1; ++j)
        {
            std::cout << flags[i][s[j] - '0'] << ".";
        }
        std::cout << flags[i][s.back() - '0'] << std::endl;;
    }
    return 0;
}

/*
  0   1   2   3   4   5   6   7   8   9
XXX ..X XXX XXX X.X XXX XXX XXX XXX XXX
X.X ..X ..X ..X X.X X.. X.. ..X X.X X.X
X.X ..X XXX XXX XXX XXX XXX ..X XXX XXX
X.X ..X X.. ..X ..X ..X X.X ..X X.X ..X
XXX ..X XXX XXX ..X XXX XXX ..X XXX XXX
*/