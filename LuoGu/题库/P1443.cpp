#include <iostream>
#include <vector>
#include <queue>

int dx[8]{ -2, -2, -1, -1,  1, 1,  2, 2 };
int dy[8]{ -1,  1, -2,  2, -2, 2, -1, 1 };

struct BfsNode
{
    int x;
    int y;
    int count;
};

int main(void)
{
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector<std::vector<int>> grid(n + 1, std::vector<int>(m + 1, -1));

    std::queue<BfsNode> bfs;
    bfs.push({ x, y, 0 });
    grid[x][y] = 0;
    while (!bfs.empty())
    {
        BfsNode b(bfs.front());
        bfs.pop();

        for (int i(0); i < 8; ++i)
        {
            if (b.x + dx[i] < 1 || b.x + dx[i] > n)
                continue;
            if (b.y + dy[i] < 1 || b.y + dy[i] > m)
                continue;
            if (grid[b.x + dx[i]][b.y + dy[i]] != -1)
                continue;
            bfs.push({ b.x + dx[i], b.y + dy[i], b.count + 1 });
            grid[b.x + dx[i]][b.y + dy[i]] = b.count + 1;
        }
    }

    for (int i(1); i <= n; ++i)
    {
        for (int j(1); j <= m; ++j)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}