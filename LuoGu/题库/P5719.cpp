#include <iostream>
#include <iomanip>

int main(void)
{
    int n, k;
    std::cin >> n >> k;
    double sumA(0), sumB(0);
    int countA(0), countB(0);
    for (int i(1); i <= n; ++i)
    {
        if (i % k)
        {
            ++countB;
            sumB += i;
        }
        else
        {
            ++countA;
            sumA += i;
        }
    }
    std::cout << std::fixed << std::setprecision(1) << sumA / countA << " " << sumB / countB << std::endl;
    return 0;
}