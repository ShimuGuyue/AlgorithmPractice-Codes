#include <iostream>
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
	int n;
	std::cin >> n;
	std::vector<int> as(n);
	std::vector<int> bs(n);
	for (int &a : as)
	{
		std::cin >> a;
	}
	for (int &b : bs)
	{
		std::cin >> b;
	}
	int ans = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (as[i] > bs[i + 1])
			ans += as[i] - bs[i + 1];
	}
	ans += as.back();
	std::cout << ans << std::endl;
}