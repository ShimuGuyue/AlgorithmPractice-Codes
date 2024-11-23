#include <iostream>
#include <vector>

void operator+=(std::vector<int>& a, std::vector<int>& b);
void operator*=(std::vector<int>& a, int b);

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> ans(100);
    std::vector<int> temp(100);
    temp[0] = 1;
    for (int i(1); i <= n; ++i)
    {
        temp *= i;
        ans += temp;
    }
    for (int i(99); i >= 0; --i)
    {
        if (ans[i] != 0)
        {
            for (int j(i); j >= 0; --j)
            {
                std::cout << ans[j];
            }
            break;
        }
    }
    std::cout << std::endl;
    return 0;
}

void operator+=(std::vector<int>& a, std::vector<int>& b)
{
    for (int i(0); i < 100; ++i)
    {
        a[i] += b[i];
        if (a[i] > 9)
        {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
    }
}

void operator*=(std::vector<int>& a, int b)
{
    for (int i(0); i < 100; ++i)
    {
        a[i] *= b;
    }
    for (int i(0); i < 100; ++i)
    {
        if (a[i] > 9)
        {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
    }
}