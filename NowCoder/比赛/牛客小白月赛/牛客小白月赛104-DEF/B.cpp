#include <iostream>
#include <iomanip>
#include <cmath>

namespace solve
{
	void Solve(void);
}

int main(void)
{
#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
#endif
	int t(1);
	//std::cin >> t;
	while (t--)
	{
		solve::Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve::Solve(void)
{
    double p1, p2, p3, p4, p5;
	std::cin >> p1 >> p2 >> p3 >> p4 >> p5;
	double ans(1);
	// 
	ans -= pow((1 - p4 - p5), 10);
	// s
	ans -= p4 * pow((1 - p4 - p5), 9) * 10;
	// u
	ans -= p5 * pow((1 - p4 - p5), 9) * 10;
	std::cout << std::fixed << std::setprecision(10) << ans << std::endl;
}