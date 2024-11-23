#include <iostream>

bool is_prime(int x);

int main(void)
{
    int n;
    std::cin >> n;
    int count(0);
    int flag(2);
    while (n >= flag)
    {
        if (is_prime(flag))
        {
            std::cout << flag << std::endl;
            n -= flag;
            ++count;
        }
        ++flag;
    }
    std::cout << count << std::endl;
    return 0;
}

bool is_prime(int x)
{
    for (int i(2); i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}