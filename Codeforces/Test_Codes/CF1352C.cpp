#include <iostream>
#include <cstdint>

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

    int32_t t = 1;
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
	int64_t n, k;
	std::cin >> n >> k;
	int64_t ans;
	if (k > n)
	{
		if (k % (n - 1) == 0)
		{
			ans = k / (n - 1) * n - 1;
		}
		else
		{
			ans = k / (n - 1) * n + k % (n - 1);
		}
	}
	else if (k == n)
	{
		ans = n + 1;
	}
	else // k < n
	{
		ans = k;
	}
	std::cout << ans << std::endl;
}