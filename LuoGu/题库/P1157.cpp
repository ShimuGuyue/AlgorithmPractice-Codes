#include <iostream>
#include <iomanip>
#include <vector>

int n, r;
std::vector<std::vector<int>> anss;

void Dfs(int index, std::vector<int> vi);

int main(void)
{
    std::cin >> n >> r;
    std::vector<int> temp;
    Dfs(1, temp);
    int m(anss.size());
    for (int i(1); i <= m; ++i)
    {
        for (int j(0); j < r; ++j)
        {
            std::cout << std::setw(3) << anss[m-i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}

void Dfs(int index, std::vector<int> vi)
{
    if (vi.size() == r)
    {
        anss.push_back(vi);
        return;
    }

    if (index > n)
    {
        return;
    }

    Dfs(index + 1, vi);
    vi.push_back(index);
    Dfs(index + 1, vi);
}