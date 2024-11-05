#include <iostream>
#include <queue>

int main(void)
{
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> as;
    while (n--)
    {
        int a;
        std::cin >> a;
        as.push(a);
    }
    int64_t ans(0);
    while (as.size() != 1)
    {
        int a(as.top());
        as.pop();
        int b(as.top());
        as.pop();
        int c(a + b);
        as.push(c);
        ans += c;
    }
    std::cout << ans << std::endl;
    return 0;
}