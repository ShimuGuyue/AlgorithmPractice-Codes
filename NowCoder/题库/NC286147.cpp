#include <iostream>
#include<cstdint>

void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
		freopen(".in.in"  , "r", stdin );
		freopen(".out.out", "w", stdout);
		#define RUN_TIME \
			std::clog << (clock() * 1.0 / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl;
	#else
		#define RUN_TIME
	#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t = 1;
	//std::cin >> t;
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
	int64_t n, k ,x;
	std::cin >> n >> k >> x;
	if (k < x * (n - 1) + 1 || k > x * (n + 1) - 1)
	{
		std::cout << -1 << std::endl;
		return;
	}
	if (k <= x * n)
		std::cout << x << " " << x + k - 1 << std::endl;
	else
		std::cout << x * (n + 1) - 1 - k + 1 << " " << x * (n + 1) - 1 << std::endl;
}