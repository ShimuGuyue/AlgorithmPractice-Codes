#include <iostream>
#include <vector>

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
	int n;
	std::cin >> n;
	std::vector<int> as(n);
	int count1 = 0;
	int ans = 0;
	for (int &a : as)
	{
		std::cin >> a;
		if (a == 1)
			++count1;
		ans = std::max(ans, a);
	}
	if (ans == 1)
	{
		ans = 0;
	}
	if (count1 ==  n - 1)
	{
		ans = ans - 1;
	}
	if (n == 1)
	{
		ans = -1;
	}
	std::cout << ans << std::endl;
}