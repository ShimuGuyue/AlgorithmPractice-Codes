#include <iostream>
#include <vector>

int n, k;
int ans(0);
std::vector<int> as;

bool Is_Prime(int x);
void Dfs(int i, int cnt, int sum);

int main(void)
{
    std::cin >> n >> k;
    as.resize(n);
    for (int& a : as)
    {
        std::cin >> a;
    }
    
    Dfs(0, 0, 0);

    std::cout << ans << std::endl;
    return 0;
}


void Dfs(int i, int cnt, int sum)
{
    if (cnt == k)
    {
        ans += Is_Prime(sum);
        return;
    }
    if (i == n)
        return;
    Dfs(i + 1, cnt, sum);
    Dfs(i + 1, cnt + 1, sum + as[i]);
}

bool Is_Prime(int x)
{
    if (x < 2)
        return false;
    for (int i(2); i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}