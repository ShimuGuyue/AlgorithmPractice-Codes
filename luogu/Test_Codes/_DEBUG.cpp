#include <iostream>
#include <vector>

int main(void)
{
    int64_t sum(0);
    std::vector<int64_t> a(31);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    sum += a[0] + a[1] + a[2];
    for (int i(3); i <= 30; ++i)
    {
        a[i] = a[i-1] + 2 * a[i-2] + 5 * a[i-3];
        sum += a[i];
    }
    std::cout << sum << std::endl;
    return 0;
}