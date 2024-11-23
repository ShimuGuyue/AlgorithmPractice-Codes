#include <iostream>
#include <vector>
#include <string>

const int64_t mod(1e9+7);

void solve(void);

int main(void)
{
	int t(1);
	//std::cin >> t;
	while (t--)
	{
		solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve(void)
{
    std::string s;
	std::cin >> s;
	int n(s.size());
	std::vector<std::vector<int64_t>> dp(n, std::vector<int64_t>(9)); // 前 i 个数，余数为 0 ~ 8
	for (int i(0); i < n; ++i)
	{
		int a(s[i] ^ '0');
		dp[i][a % 9] = 1; // 只包含第 i 个数

		if (i == 0)
			continue;

		for (int j(0); j < 9; ++j)
		{
			dp[i][j] += dp[i-1][j]; // 前 i-1 个数
			dp[i][j] += dp[i-1][(9-a+j)%9]; // 前 i 个数
			dp[i][j] %= mod;
		}
	}
	std::cout << dp.back()[0] << std::endl;
}