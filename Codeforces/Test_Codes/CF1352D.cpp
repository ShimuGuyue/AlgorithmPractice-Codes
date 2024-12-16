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
	int32_t flag = 0;
	int i = 0, j = n - 1;
	while (1)
	{
		
	}
}