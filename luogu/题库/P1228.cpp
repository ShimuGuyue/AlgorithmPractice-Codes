// 参考教程
// https://www.bilibili.com/video/BV1JY4y1Z743/?spm_id_from=333.337.search-card.all.click&vd_source=fe9156abafd89942972a6860493f9a04
// https://www.bilibili.com/video/BV1Qb4y177Ct/?spm_id_from=333.337.search-card.all.click&vd_source=fe9156abafd89942972a6860493f9a04
#include <iostream>

void Dfs(int x, int y, int a, int b, int size);

int main(void)
{
    int k;
    std::cin >> k;
    k = 1 << k; // k = pow(2, k);
    int x, y;
    std::cin >> x >> y;
    Dfs(x, y, 1, 1, k);
    return 0;

}

void Dfs(int x, int y, int a, int b, int size)
{
    if (size == 1)
        return;
    
    if      (x - a <= size / 2 - 1 && y - b <= size / 2 - 1)
    {
        std::cout << a + size / 2  << " " << b + size / 2 << " " << 1 << std::endl;

        Dfs(x               , y               , a           , b           , size / 2);
        Dfs(a + size / 2 - 1, b + size / 2    , a           , b + size / 2, size / 2);
        Dfs(a + size / 2    , b + size / 2 - 1, a + size / 2, b           , size / 2);
        Dfs(a + size / 2    , b + size / 2    , a + size / 2, b + size / 2, size / 2);
    }
    else if (x - a <= size / 2 - 1 && y - b > size / 2 - 1)
    {
        std::cout << a + size / 2  << " " << b + size / 2 - 1 << " " << 2 << std::endl;

        Dfs(a + size / 2 - 1, b + size / 2 - 1, a           , b           , size / 2);
        Dfs(x               , y               , a           , b + size / 2, size / 2);
        Dfs(a + size / 2    , b + size / 2 - 1, a + size / 2, b           , size / 2);
        Dfs(a + size / 2    , b + size / 2    , a + size / 2, b + size / 2, size / 2);
    }
    else if (x - a > size / 2 - 1 && y - b <= size / 2 - 1)
    {
        std::cout << a + size / 2 - 1  << " " << b + size / 2 << " " << 3 << std::endl;

        Dfs(a + size / 2 - 1, b + size / 2 - 1, a           , b           , size / 2);
        Dfs(a + size / 2 - 1, b + size / 2    , a           , b + size / 2, size / 2);
        Dfs(x               , y               , a + size / 2, b           , size / 2);
        Dfs(a + size / 2    , b + size / 2    , a + size / 2, b + size / 2, size / 2);
    }
    else // (x - a > size / 2 - 1 && y - b > size / 2 - 1)
    {
        std::cout << a + size / 2 - 1  << " " << b + size / 2 - 1 << " " << 4 << std::endl;

        Dfs(a + size / 2 - 1, b + size / 2 - 1, a           , b           , size / 2);
        Dfs(a + size / 2 - 1, b + size / 2    , a           , b + size / 2, size / 2);
        Dfs(a + size / 2    , b + size / 2 - 1, a + size / 2, b           , size / 2);
        Dfs(x               , y               , a + size / 2, b + size / 2, size / 2);
    }
}