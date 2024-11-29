#include <iostream>
#include <vector>
#include <iomanip>

int n;
double p;
std::vector<double> as;
std::vector<double> bs;

bool Check(double t);
double Binary_Search(double l, double r);

int main(void)
{
    std::cin >> n >> p;
    as = std::vector<double>(n);
    bs = std::vector<double>(n);
    double sum_b(0);
    for (int i(0); i < n; ++i)
    {
        std::cin >> as[i] >> bs[i];
        sum_b += bs[i];
    }
    if (sum_b <= p)
    {
        std::cout << -1 << std::endl;
        return 0;
    }
    double ans(Binary_Search(0.000000, 1000000000.000000));
    std::cout << std::fixed << std::setprecision(6) << ans << std::endl;
    return 0;
}

bool Check(double t)
{
    double sum(0);
    for (int i(0); i < n; ++i)
    {
        if (bs[i] - as[i] * t < 0)
        {
            sum += as[i] * t - bs[i];
        }
    }
    return sum > p * t;
}

double Binary_Search(double l, double r)
{
    while (l < r - 1e-6)
    {
        double mid((l + r) / 2);
        if (Check(mid))
            r = mid;
        else
            l = mid;   
    }
    return r; 
}