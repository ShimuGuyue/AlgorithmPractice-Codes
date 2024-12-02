// O2
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> anss;

void Dfs(int n, int x, int y, std::vector<int> rs, std::vector<int> cs, std::vector<int> diagonal_ls, std::vector<int> diagonal_rs, std::vector<int> ys);

int main(void)
{
    int n;
    std::cin >> n;

    std::vector<int> rs(n + 1);              // 行
    std::vector<int> cs(n + 1);              // 列
    std::vector<int> diagonal_ls(2 * n - 1); // 左对角线
    std::vector<int> diagonal_rs(2 * n - 1); // 右对角线
    std::vector<int> ys;
    for (int i(1); i <= n; ++i)
    {
        Dfs(n, 1, i, rs, cs, diagonal_ls, diagonal_rs, ys);
    }

    std::sort(anss.begin(), anss.end());

    for (int i(0); i < 3; ++i)
    {
        for (int j(0); j < anss[i].size(); ++j)
        {
            std::cout << anss[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << anss.size() << std::endl;
    return 0;
}

void Dfs(int n, int x, int y, std::vector<int> rs, std::vector<int> cs, std::vector<int> diagonal_ls, std::vector<int> diagonal_rs, std::vector<int> ys)
{
    ys.push_back(y);

    if (x == n)
    {
        anss.push_back(ys);
        return;
    }

    rs[x] = 1;
    cs[y] = 1;
    diagonal_ls[x + y - 2] = 1;
    diagonal_rs[x - y + n - 1] = 1;

    for (int i(1); i <= n; ++i)
    {
        if (rs[x + 1] || cs[i] || diagonal_ls[x + 1 + i - 2] || diagonal_rs[x + 1 - i + n - 1])
            continue;
        Dfs(n, x + 1, i, rs, cs, diagonal_ls, diagonal_rs, ys);
    }
}