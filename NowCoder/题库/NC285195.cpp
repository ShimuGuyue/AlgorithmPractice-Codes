#include <iostream>
#include <vector>

void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t(1);
	std::cin >> t;
	while (t--)
	{
		Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void Solve(void)
{
    int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::vector<std::vector<int>> indexs(26);
	for (int i(0); i < n; ++i)
	{
		indexs[s[i] - 'a'].push_back(i);
	}
	int ans(n);
	for (int k(0); k < 26; ++k)
	{
		std::vector<int>& v(indexs[k]);
		int m(v.size());
		if (m == 1 || m == 0)
			continue;
		// std::cout << (char)(k+'a') << " " << m << std::endl;
		for (int i(0); i < m - 1; ++i)
		{
			// std::cout << v[i] << " " << v[i + 1] << std::endl;
			ans = std::min(ans, v[i + 1] - v[i] - 1);
		}
		int len(v.front() + n - v.back() - 1);
		// std::cout << len << std::endl;
		ans = std::min(ans, len);
	}
	if (ans == n)
		std::cout << -1 << std::endl;
	else
		std::cout << ans << std::endl;
}