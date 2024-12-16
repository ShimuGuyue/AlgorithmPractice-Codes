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

	std::vector<int32_t> next_0s(n, -1);
	std::vector<int32_t> next_1s(n, -1);
	int32_t index1 = -1, index0 = -1;
	for (int32_t i = n - 1; i >= 0; --i)
	{
		next_0s[i] = index0;
		next_1s[i] = index1;

		if (s[i] == '0')
			index0 = i;
		else // == '1'
			index1 = i;
	}

	std::vector<int64_t> dp(n, INT64_MAX);
	dp[0] = 0;
	for (int32_t i = 0; i < n; ++i)
	{
		if (s[i] == '1')
		{
			if (next_1s[i] != -1)
				dp[next_1s[i]] = std::min(dp[next_1s[i]], dp[i] + x);
			if (next_0s[i] != -1)
				dp[next_0s[i]] = std::min(dp[next_0s[i]], dp[i] + y);
		}
		else // == '0'
		{
			if (next_0s[i] != -1)
				dp[next_0s[i]] = std::min(dp[next_0s[i]], dp[i] + x);
			if (next_1s[i] != -1)
				dp[next_1s[i]] = std::min(dp[next_1s[i]], dp[i] + y);
		}
	}
	int64_t ans = dp.back();
	std::cout << ans << std::endl;
}