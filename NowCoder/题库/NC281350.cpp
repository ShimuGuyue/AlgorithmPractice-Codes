#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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
	std::map<char, int> m;
	for (char c : s)
	{
		++m[c];
		if (m[c] > n / 2)
		{
			std::cout << -1 << std::endl;
			return;
		}
	}
	std::vector<std::pair<char, int>> alphas(m.begin(), m.end());
	std::string ans;
	for (int i(0); i < n; ++i)
	{
		std::sort(alphas.begin(), alphas.end(),
		[](std::pair<char, int> a, std::pair<char, int> b)
		{
			return a.second > b.second;
		});
		bool find(false);
		for (std::pair<char, int>& ci : alphas)
		{
			if (ci.first != s[i] && ci.second)
			{
				ans += ci.first;
				--ci.second;
				find = true;
				break;
			}
		}
		if (!find)
		{
			for (int j(0); j < ans.size(); ++j)
			{
				if (ans[j] != s[i] && s[j] != s[i])
				{
					ans += ans[j];
					ans[j] = s[i];
					break;
				}
			}
		}
	}
	std::cout << ans << std::endl;
} 