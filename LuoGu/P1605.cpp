#include <iostream>
#include <vector>

int n, m, t;
int xs, ys, xf, yf;
std::vector<std::vector<int>> grid;
int ans;

int dxy[4][2]{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void Dfs(int x, int y);

int main(void)
{
    // int n, m, t;
    std::cin >> n >> m >> t;
    // int xs, xy, xf, yf;
    std::cin >> xs >> ys >> xf >> yf;
    // std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    grid = std::vector<std::vector<int>>(n + 1, std::vector<int>(m + 1));

    for (int i(0); i < t; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        grid[x][y] = 2;
    }

    // int ans(0);
    ans = 0;

    grid[xs][ys] = 1;
    Dfs(xs, ys);
    std::cout << ans << std::endl;
    return 0;
}

void Dfs(int x, int y)
{
    if (x == xf && y == yf)
    {
        ++ans;
        return;
    }

    for (int i(0); i < 4; ++i)
    {
        if (x + dxy[i][0] < 1 || x + dxy[i][0] > n)
            continue;
        if (y + dxy[i][1] < 1 || y + dxy[i][1] > m)
            continue;
        if (grid[x + dxy[i][0]][y + dxy[i][1]])
            continue;

        grid[x + dxy[i][0]][y + dxy[i][1]] = 1;
        Dfs(x + dxy[i][0], y + dxy[i][1]);
        grid[x + dxy[i][0]][y + dxy[i][1]] = 0;
    }
}