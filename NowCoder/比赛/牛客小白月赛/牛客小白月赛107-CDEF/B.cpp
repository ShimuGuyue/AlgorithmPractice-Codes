#include <iostream>
#include <map>

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

    int t(1);
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
	int n;
	std::cin >> n;
	std::map<int, int> counts;
	while (n--)
	{
		int a;
		std::cin >> a;
		++counts[a];
	}
	int min(counts.begin()->first);
	int	max(counts.rbegin()->first);
	std::cout << max - min << " " << (max + min + 1) / 2 << std::endl;
}