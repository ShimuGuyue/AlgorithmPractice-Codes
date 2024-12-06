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
	int n(s.size());
	for (int i(1); i < n; ++i)
	{
		for (int j(i); j >= 1 ; --j)
		{
			if (s[j] - 1 > s[j - 1])
			{
				--s[j];
				std::swap(s[j], s[j - 1]);
			}
			else
				break;
		}
	}
	std::cout << s << std::endl;
}

/**
 * 	1709
 * 	1780
 * 	6180
 * 	6710
 */