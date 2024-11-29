/**
 * 公式：sum(w / pow(1 + p, i)) == w0，i = [1, m]
 */
#include <iostream>
#include <iomanip>
#include <cmath>

bool Check(double k, double w0, double w, int m);
double Binary_Search(double l, double r, double w0, double w, int m);

int main(void)
{
    double w0, w;
    int m;
    std::cin >> w0 >> w >> m;
    double l(0.00000), r(3.00000);
    double ans(Binary_Search(l ,r, w0, w, m) * 100);
    std::cout << std::fixed << std::setprecision(1) << ans << std::endl;
    return 0;
}

double Binary_Search(double l, double r, double w0, double w, int m)
{
    while (l < r - 0.00001)
    {
        // std::cout << l << " " << r << std::endl;
        double mid((l + r) / 2);
        if (Check(mid, w0, w, m))
            r = mid;
        else
            l = mid;   
    }
    return r; 
}

bool Check(double k, double w0, double w, int m)
{
    double sum(0);
    for (int i(1); i <= m; ++i)
    {
        sum += w / pow(1 + k, i);
    }
    return sum <= w0;
}