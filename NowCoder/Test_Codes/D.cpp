#include <iostream>
#include <cstdint>
#include <vector>

#pragma GCC optimize(2)

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
	int32_t n, x, y;
	std::cin >> n >> x >> y;
	std::string s;
	std::cin >> s;
	std::vector<int32_t> index0s;
	std::vector<int32_t> index1s;
	for (int32_t i = 0; i < n; ++i)
	{
		if (s[i] == '1')
			index1s.push_back(i);
		else	// s[i] == '0'
			index0s.push_back(i);
	}
	// for (int32_t i : index0s)std::cout<<i<<" ";std::cout << std::endl;
	// for (int32_t i : index1s)std::cout<<i<<" ";std::cout << std::endl;
	std::vector<int64_t> dp(n, INT64_MAX);
	dp[0] = 0;
	int32_t a, b;
	if (s[0] == '1')
		a = 1, b = 0;
	else // s[0] == '0'
		a = 0, b = 1;
	for (int32_t i = 0; i < n; ++i)
	{
		std::cout << i << std::endl;
		std::cout << a << " " << b << std::endl;
		std::cout << index1s[a] << " " << index0s[b] << std::endl;
		if (s[i] == '1')
		{
			if (a < index1s.size())
				dp[index1s[a]] = std::min(dp[index1s[a]], dp[i] + x);

			if (a > i + 1 && i + 1 < n)
				dp[i + 1] = std::min(dp[i + 1], dp[i] + y);
			else
			{
				for (int32_t index : index0s)
				{
					if (index > i)
					{
						dp[index] = std::min(dp[index], dp[i] + y);
						break;
					}
				}
			}

			++a;
		}
		else // s[i] == '0'
		{
			if (b < index0s.size())
				dp[index0s[b]] = std::min(dp[index0s[b]], dp[i] + x);

			if (b > i + 1 && i + 1 < n)
				dp[i + 1] = std::min(dp[i + 1], dp[i] + y);
			else
			{
				for (int32_t index : index1s)
				{
					if (index > i)
					{
						dp[index] = std::min(dp[index], dp[i] + y);
						break;
					}
				}
			}

			++b;
		}
	}
	int64_t ans = dp.back();
	std::cout << ans << std::endl;
}