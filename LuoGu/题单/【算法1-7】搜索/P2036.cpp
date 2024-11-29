#include <iostream>
#include <vector>

void dfs(int index, int n, int s, int b, std::vector<int>& ss, std::vector<int>& bs, int& ans);

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> ss(n);
    std::vector<int> bs(n);
    for (int i(0); i < n; ++i)
    {   
        std::cin >> ss[i] >> bs[i];
    }
    int ans(1e9);
    dfs(0, n, 1, 0, ss, bs, ans);
    std::cout << ans << std::endl;
    return 0;
}

void dfs(int index, int n, int s, int b, std::vector<int>& ss, std::vector<int>& bs, int& ans)
{
    if (index > n)
        return;

    if (s != 1 && b != 0)
        ans = std::min(ans, abs(s - b));

    dfs(index + 1, n, s, b, ss, bs, ans);
    dfs(index + 1, n, s * ss[index], b + bs[index], ss, bs, ans);
}