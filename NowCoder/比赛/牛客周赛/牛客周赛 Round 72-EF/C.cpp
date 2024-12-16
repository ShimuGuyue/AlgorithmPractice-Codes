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
	int32_t a, b, k;
	std::cin >> a >> b >> k;
	if (k > std::min(a, b) * 2 || k == a + b || (k == 0 && (a != 0 && b != 0)))
	{
		std::cout << -1 << std::endl;
		return;
	}
	int c = b < a;

	if ((k & 1) == 0)
	{
		if (a < b)
		{
			for (int32_t i = 0; i < k / 2; ++i)
			{
				std::cout << "10";
			}
			for (int32_t i = 0; i < a - k / 2; ++i)
			{
				std::cout << "0";
			}
			for (int32_t i = 0; i < b - k / 2; ++i)
			{
				std::cout << "1";
			}
		}
		else // b < a
		{
			for (int32_t i = 0; i < k / 2; ++i)
			{
				std::cout << "01";
			}
			for (int32_t i = 0; i < b - k / 2; ++i)
			{
				std::cout << "1";
			}
			for (int32_t i = 0; i < a - k / 2; ++i)
			{
				std::cout << "0";
			}
		}
	}
	else
	{
		if (a < b)
		{
			int32_t flag = k / 2;
			for (int32_t i = 0; i < a - flag; ++i)
			{
				std::cout << "0";
			}
			for (int32_t i = 0; i < flag; ++i)
			{
				std::cout << "10";
			}
			for (int32_t i = 0; i < b - flag; ++i)
			{
				std::cout << "1";
			}
		}
		else // b < a
		{
			int32_t flag = k / 2;
			for (int32_t i = 0; i < b - flag; ++i)
			{
				std::cout << "1";
			}
			for (int32_t i = 0; i < flag; ++i)
			{
				std::cout << "01";
			}
			for (int32_t i = 0; i < a - flag; ++i)
			{
				std::cout << "0";
			}
		}
	}
	std::cout << std::endl;
}