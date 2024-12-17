#include <iostream>
#include <cstdint>
#include <vector>

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
	int32_t n;
	std::cin >> n;
	std::vector<int32_t> as(n);
	for (int32_t i = 0; i < n; ++i)
	{
		std::cin >> as[i];
	}
	int32_t count = 0;
	int32_t i = 0, j = n - 1;
	int32_t sum_a = 0, sum_b = 0;
	int32_t a = 0, b = 0;
	while (1)
	{
		int32_t sum = 0;
		bool ok = true;
		while (sum <= b)
		{
			if (i > j)
			{
				ok = false;
				break;
			}
			sum += as[i];
			++i;
		}
		if (sum)
			++count;
		a = sum;
		sum_a += a;
		if (!ok)
			break;

		sum = 0;
		ok = true;
		while (sum <= a)
		{
			if (j < i)
			{
				ok = false;
				break;
			}
			sum += as[j];
			--j;
		}
		if (sum)
			++count;
		b = sum;
		sum_b += b;
		if (!ok)
			break;
	}
	
	std::cout << count << " " << sum_a << " " << sum_b << std::endl;
}