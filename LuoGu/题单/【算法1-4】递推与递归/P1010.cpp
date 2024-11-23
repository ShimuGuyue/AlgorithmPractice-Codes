#include <iostream>

void turn(int n);

int main(void)
{
    int n;
    std::cin >> n;
    while (n)
    {
        int count(0);
        int flag(1);
        while (flag < n)
        {
            flag *= 2;
            ++count;
        }
        if (flag == n)
        {
            turn(count);
            n -= flag;
        }
        else // flag > n
        {
            turn(count - 1);
            n -= flag / 2;
        }

        if (n)
            std::cout << "+";
    }
    std::cout << std::endl;
    return 0;
}

void turn(int n)
{
    if (n == 1)
        std::cout << 2;
    else
    {
        std::cout << "2(";
        if (n == 0)
            std::cout << "0";
        else
        {
            while (n)
            {
                int count(0);
                int flag(1);
                while (flag < n)
                {
                    flag *= 2;
                    ++count;
                }
                if (flag == n)
                {
                    turn(count);
                    n -= flag;
                }
                else // flag > n
                {
                    turn(count - 1);
                    n -= flag / 2;
                }

                if (n)
                    std::cout << "+";
            }
        }
        std::cout << ")";
    }
}