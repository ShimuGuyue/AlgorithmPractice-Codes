#include <iostream>
#include <vector>

bool is_prime(int x);

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& i : a)
    {
        std::cin >> i;
    }
    std::vector<int> anss;
    for (int i : a)
    {
        if (is_prime(i))
            anss.push_back(i);
    }
    for (int i : anss)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}

bool is_prime(int x)
{
    if (x == 1)
        return false;
    for (int i(2); i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}