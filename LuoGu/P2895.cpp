#include <iostream>
#include <vector>
#include <queue>

int dx[5]{ -1,  0, 0, 0, 1 };
int dy[5]{  0, -1, 0, 1, 0 };

struct BfsData
{
    int x;
    int y;
    int t;
};

int main(void)
{
    std::vector<std::vector<int>> grid (303, std::vector<int>(303, 2000));
    std::vector<std::vector<int>> flags(303, std::vector<int>(303));

    int m;
    std::cin >> m;
    for (int i(0); i < m; ++i)
    {
        int x, y, t;
        std::cin >> x >> y >> t;
        for (int j(0); j < 5; ++j)
        {
            if (x + dx[j] < 0 || y + dy[j] < 0)
                continue;
            if (t < grid[x + dx[j]][y + dy[j]])
                grid[x + dx[j]][y + dy[j]] = t;
        }
    }

    std::queue<BfsData> bfs;
    bfs.push({ 0, 0, 0 });
    flags[0][0] = 1;
    while (!bfs.empty())
    {  
        BfsData b(bfs.front());
        bfs.pop();

        if (grid[b.x][b.y] == 2000)
        {
            std::cout << b.t << std::endl;
            return 0;
        }

        for (int i(0); i < 5; ++i)
        {
            if (b.x + dx[i] < 0 || b.y + dy[i] < 0)
                continue;
            if (flags[b.x + dx[i]][b.y + dy[i]] == 1)
                continue;
            if (grid[b.x + dx[i]][b.y + dy[i]] <= b.t + 1)
                continue;

            flags[b.x + dx[i]][b.y + dy[i]] = 1;
            bfs.push({b.x + dx[i], b.y + dy[i], b.t + 1});
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}