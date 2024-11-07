#include <iostream>
#include <vector>

int64_t n, l, r;
std::vector<int> values;
std::vector<std::vector<int>> edges;
int ans(0);

void Dfs(int last, int now, int64_t sum);

int main(void)
{
    std::cin >> n >> l >> r;
    values = std::vector<int>(n + 1);
    for (int i(1); i <= n; ++i)
    {
        char value;
        std::cin >> value;
        values[i] = value ^ '0';
    }
    edges = std::vector<std::vector<int>>(n + 1);
    for (int i(1); i < n; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i(1); i <= n; ++i)
    {
        Dfs(-1, i, values[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}

void Dfs(int last, int now, int64_t sum)
{
    for (int node : edges[now])
    {
        if (node == last)
            continue;
        int64_t new_sum = (sum << 1) + (values[node]);
        if (new_sum > r)
            continue;
        if (l <= new_sum && new_sum <= r)
            ++ans;
        Dfs(now, node, new_sum);
    }
}