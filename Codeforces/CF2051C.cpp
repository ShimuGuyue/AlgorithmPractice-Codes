#include <iostream>
#include <vector>
#include <set>

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
	int n, m, k;
	std::cin >> n >> m >> k;
	std::set<int> problems;
	std::vector<int> as(m);
	std::vector<int> qs(k);
	for (int &a : as)
	{
		std::cin >> a;
	}
	for (int &q : qs)
	{
		std::cin >> q;
		problems.insert(q);
	}
	if (k == n)
	{
		for (int i = 0; i < m; ++i)
		{
			std::cout << 1;
		}
	}
	else if (k == n - 1)
	{
		for (int i = 0; i < m; ++i)
		{
			if (problems.find(as[i]) == problems.end())
				std::cout << 1;
			else
				std::cout << 0;
		}
	}
	else
	{
		for (int i = 0; i < m; ++i)
		{
			std::cout << 0;
		}
	}
	std::cout << std::endl;
}