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
	std::string t;
	std::cin >> s;
	std::cin >> t;
	
	int i(0), j(0);
	while (i < s.size() && j < t.size())
	{
		if (s[i] == t[j] || s[i] == '?')
		{
			s[i] = t[j];
			++j;
		}
		++i;
	}

	if (j != t.size())
	{
		std::cout << "NO" << std::endl;
		return;
	}
	std::cout << "YES" << std::endl;
	for (char& c : s)
	{
		if (c == '?')
			c = 'a';
	}
	std::cout << s << std::endl;
}