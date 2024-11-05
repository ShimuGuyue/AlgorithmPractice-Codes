#include <iostream>
#include <vector>
#include <map>

using Mode = std::pair<std::pair<std::pair<int, int>, std::pair<int, int>>, std::pair<int, int>>;

void Move(int& x, int& y, std::vector<std::vector<char>>& grid, int n, int& mode);

int main(void)
{
    const int n(10);
    std::vector<std::vector<char>> grid(n, std::vector<char>(n));
    for (std::vector<char>& vc : grid)
    {
        for (char& c : vc)
        {
            std::cin >> c;
        }
    }
    int xC, yC, xF, yF;
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < n; ++j)
        {
            if (grid[i][j] == 'F')
                xF = i, yF = j;
            else if (grid[i][j] == 'C')
                xC = i, yC = j;
        }
    }
    int modeC(1), modeF(1); // 1->U 2->R 3->D 4->L

    std::map<Mode, int> modes;
    int ans(0);
    while (1)
    {
        ++ans;
        if (modes[{{{xC, yC}, {xF, yF}}, {modeC, modeF}}])
        {
            ans = 0;
            break;
        }
        ++modes[{{{xC, yC}, {xF, yF}}, {modeC, modeF}}];
        Move(xC, yC, grid, n, modeC);
        Move(xF, yF, grid, n, modeF);
        if (xC == xF && yC == yF)
            break;
    }
    std::cout << ans << std::endl;
    return 0;
}

void Move(int& x, int& y, std::vector<std::vector<char>>& grid, int n, int& mode)
{
    if (mode == 1)
    {
        if (x != 0 && grid[x - 1][y] != '*')
            --x;
        else
            mode = 2;
    }
    else if (mode == 2)
    {
        if (y != n - 1 && grid[x][y + 1] != '*')
            ++y;
        else
            mode = 3;
    }
    else if (mode == 3)
    {
        if (x != n - 1 && grid[x + 1][y] != '*')
            ++x;
        else
            mode = 4;
    }
    else if (mode == 4)
    {   
        if (y != 0 && grid[x][y - 1] != '*')
            --y;
        else
            mode = 1;
    }
}