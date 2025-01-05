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
	std::vector<int> as(7);
	int ans = 1e9;
	for (int &a : as)
	{
		std::cin >> a;
		ans = std::min(ans, a);
	}
	std::cout << ans << std::endl;
}