#include <iostream>

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
	int x, y;
	std::cin >> x >> y;
	int time = y / (x + 1);
	int ans = time * 2;
	int flag = time * (x + 1);
	if (flag == y)
	{
		if (x == 0)
			--ans;
	}
	else
	{
		if (y - flag == 1)
			++ans;
		else
			ans += 2;
	}
	if (y == 0)
		ans = 0;
	std::cout << ans << std::endl;
}