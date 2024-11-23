//O2
#include <iostream>
#include <vector>
#include <algorithm>

inline void read(int &x);

int main(void)
{
    int n, m;
    read(n);
    read(m);
    std::vector<int> a(n);
    for (int& i : a)
    {
        read(i);
    }
    std::sort(a.begin(), a.end());
    int ans(a[m]);
    std::cout << ans << std::endl;
    return 0;
}

inline void read(int &x)
{
    x = 0;
    bool flag(0);
    char c(getchar());
    while (!isdigit(c))
    { 
        flag = c == '-';
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 1) + (x << 3) + (c ^ '0'); // x * 10 + c - '0'
        c = getchar();
    } 
    flag ? x = -x : 0;
}