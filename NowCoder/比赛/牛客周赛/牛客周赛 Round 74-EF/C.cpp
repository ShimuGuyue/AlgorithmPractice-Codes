#include <iostream>
#include <cmath>

void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
		freopen(".in.in"  , "r", stdin );
		freopen(".out.out", "w", stdout);
	#else
		#define RUN_TIME
	#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t = 1;
	std::cin >> t;
	while (t--)
	{
		Solve();
		//std::cout << std::endl;
	}
	RUN_TIME
	return 0;
}

void Solve(void)
{
	int n, m;
	std::cin >> n >> m;
	while (m)
	{
		if (n > 0)
		{
			if (n <= 3)
				--n;
			else if (n <= 6)
				n = std::ceil(double(n) / 2);
			else
				n = std::ceil(std::sqrt(n));
			--m;
		}
		else
		{
			n -= m;
			break;
		}
	}
	std::cout << n << std::endl;
}