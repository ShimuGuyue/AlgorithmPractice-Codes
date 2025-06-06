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
	std::string s;
	std::cin >> s;
	std::vector<int> ans(n);
	std::set<int> t;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '0')
		{
			if (i == n - 1)
			{
				std::cout << -1 << std::endl;
				return;
			}
			ans[i] = (i + 1) + 1;
			t.insert(ans[i]);
		}
	}
	int j = 1;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '0')
			continue;
		for ( ; j <= n; ++j)
		{
			if (t.find(j) == t.end())
			{
				ans[i] = j;
				t.insert(j);
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		std::cout << ans[i] << " ";
	}
	std::cout << std::endl;
}