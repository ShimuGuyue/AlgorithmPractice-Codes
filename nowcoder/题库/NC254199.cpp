#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> hs(8+1);
    while (n--)
    {
        int a, b;
        std::cin >> a >> b;
        if (a == 0)
        {
            int h0(hs[b]);
            int h1(hs[b+1]);
            hs[b] = std::max(h0, h1) + 3;
            hs[b+1] = std::max(h0, h1) + 1;
        }
        else if (a == 90)
        {
            int h0(hs[b]);
            int h1(hs[b+1]);
            int h2(hs[b+2]);
            hs[b] = std::max(std::max(h0, h1 - 1), h2 - 1) + 2;
            hs[b+1] = std::max(std::max(h0 + 1, h1), h2) + 1;
            hs[b+2] = std::max(std::max(h0 + 1, h1), h2) + 1;
        }
        else if (a == 180)
        {
            int h0(hs[b]);
            int h1(hs[b+1]);
            hs[b] = std::max(h0, h1 + 2) + 1;
            hs[b+1] = std::max(h0 - 2, h1) + 3;
        }
        else if (a == 270)
        {
            int h0(hs[b]);
            int h1(hs[b+1]);
            int h2(hs[b+2]);
            hs[b] = std::max(std::max(h0, h1), h2) + 1;
            hs[b+1] = std::max(std::max(h0, h1), h2) + 1;
            hs[b+2] = std::max(std::max(h0, h1), h2) + 2;
        }
    }
    for (int i(1); i <= 8; ++i)
    {
        std::cout << hs[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}