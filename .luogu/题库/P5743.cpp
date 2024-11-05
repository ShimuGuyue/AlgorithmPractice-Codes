#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int64_t> a(n);
    a.back() = 1;
    for (int i(n - 1 - 1); i >= 0; --i)
    {
        a[i] = a[i + 1] + 1;
        a[i] *= 2;
    } 
    int64_t ans(a.front());
    std::cout << ans << std::endl;
    return 0;
}