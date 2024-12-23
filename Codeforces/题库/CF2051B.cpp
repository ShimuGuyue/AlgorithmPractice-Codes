#include <iostream>

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
	int n, a, b, c;
	std::cin >> n >> a >> b >> c;
	int ans = n / (a + b + c);
	n -= ans * (a + b + c);
	ans *= 3;
	if (n == 0)
		ans = ans;
	else if (n <= a)
		ans += 1;
	else if (n <= a + b)
		ans += 2;
	else if (n <= a + b + c)
		ans += 3;
	std::cout << ans << std::endl;
}