#include <iostream>
#include <queue>

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::queue<int> q;
    for (int i(1); i <= n; ++i)
    {
        q.push(i);
    }
    int count(0);
    while (!q.empty())
    {
        ++count;
        if (count % m == 0)
            std::cout << q.front() << " ";
        else
            q.push(q.front());
        q.pop();
    }
    std::cout << std::endl;
    return 0;
}