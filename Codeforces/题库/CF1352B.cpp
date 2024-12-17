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
	int32_t n, k;
	std::cin >> n >> k;
	int32_t flag;
	// k 个奇数
	flag = n - (k - 1) * 1;
	if (flag > 0 && (flag & 1))
	{
		std::cout << "YES" << std::endl;
		for (int  i = 1; i < k; ++i)
		{
			std::cout << 1 << " ";
		}
		std::cout << flag << std::endl;
		return;
	}
	// k 个偶数
	flag = n - (k - 1) * 2;
	if (flag > 0 && !(flag & 1))
	{
		std::cout << "YES" << std::endl;
		for (int  i = 1; i < k; ++i)
		{
			std::cout << 2 << " ";
		}
		std::cout << flag << std::endl;
		return;
	}

	std::cout << "NO" << std::endl;
}