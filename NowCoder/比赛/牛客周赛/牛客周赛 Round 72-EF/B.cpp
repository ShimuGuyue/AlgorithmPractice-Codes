#include <iostream>
#include <cstdint>

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
	std::string s;
	std::cin >> s;
	s += s.back();
	int32_t n = s.size();
	int64_t ans = 0;
	for (int32_t i = 1; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (s[j] == s[j - 1])
			{
				int64_t len = j - i + 1;
				ans += len * (len - 1) / 2;
				i = j + 1;
			}
		}
	}
	std::cout << ans << std::endl;
}