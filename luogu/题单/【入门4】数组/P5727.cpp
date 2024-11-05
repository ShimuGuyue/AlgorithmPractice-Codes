#include <iostream>
#include <stack>

int main(void)
{
    int n;
    std::cin >> n;
    std::stack<int> k;
    while (n != 1)
    {
        k.push(n);
        if (n % 2)
            n = n * 3 + 1;
        else
            n /= 2;
    }
    std::cout << 1;
    while (!k.empty())
    {
        std::cout << " " << k.top();
        k.pop();
    }
    std::cout << std::endl;
    return 0;
}