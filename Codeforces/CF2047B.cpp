#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif

    // 关闭输入输出缓存，使效率提升
    std::ios::sync_with_stdio(false);
    // 解除cin和cout的默认绑定，来降低IO的负担使效率提升
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

	if (n == 1)
	{
		std::cout << s << std::endl;
		return;
	}

	std::map<char, int> counts_m;
	for (char c : s)
	{
		++counts_m[c];
	}
	std::vector<std::pair<char, int>> counts_v(counts_m.begin(), counts_m.end());
	std::sort(counts_v.begin(), counts_v.end(),
		[](std::pair<char, int> a, std::pair<char, int> b)
		{
			return a.second < b.second;
		});
	for (char& c : s)
	{
		if (c == counts_v.front().first)
		{
			c = counts_v.back().first;
			break;
		}
	}
	std::cout << s << std::endl;
}