#include <iostream>
#include <vector>
#include <queue>

struct BfsNode
{
    int loc;
    int count;
};


int main(void)
{
    int n, a, b;
    std::cin >> n >> a >> b;
    std::vector<int> ks(n + 1);
    for (int i(1); i <= n; ++i)
    {
        std::cin >> ks[i];
    }

    std::vector<int> flags(n + 1);
    std::queue<BfsNode> bfs;
    bfs.push({ a, 0 });
    flags[a] = 1;
    while (!bfs.empty())
    {
        BfsNode bb(bfs.front());
        bfs.pop();

        if (bb.loc == b)
        {
            std::cout << bb.count << std::endl;
            return 0;
        }

        if (bb.loc - ks[bb.loc] >= 1 && flags[bb.loc - ks[bb.loc]] == 0)
        {
            bfs.push({bb.loc - ks[bb.loc], bb.count + 1});
            flags[bb.loc - ks[bb.loc]] = 1;
        }
        if (bb.loc + ks[bb.loc] <= n && flags[bb.loc + ks[bb.loc]] == 0)
        {
            bfs.push({bb.loc + ks[bb.loc], bb.count + 1});
            flags[bb.loc + ks[bb.loc]] = 1;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}