#include <iostream>

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
    std::string s;
	std::cin >> s;
	if (s.size() == 1)
	{
		std::cout << -1 << std::endl;
		return;
	}
	for (int i(0); i < s.size() - 2; ++i)
	{
		if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2])
		{
			std::cout << s[i] << s[i + 1] << s[i + 2] << std::endl;
			return;
		}
	}
	for (int i(0); i < s.size() - 1; ++i)
	{
		if (s[i] == s[i + 1])
		{
			std::cout << s[i] << s[i + 1] << std::endl;
			return;
		}
	}
	std::cout << -1 << std::endl;
}