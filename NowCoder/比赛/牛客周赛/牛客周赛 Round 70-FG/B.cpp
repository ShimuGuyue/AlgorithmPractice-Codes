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
	//std::cin >> t;
	while (t--)
	{
		Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void Solve(void)
{
    int x, y, k, t;
	char c;
	std::cin >> x >> y >> k >> t >> c;
	int ans;
	if (c == 'G')
	{
		if (k >= t)
		{
			ans = t;
		}
		else
		{
			ans = k + x + t;
		}
	}
	else if (c == 'R')
	{
		ans = k + t;
	}
	std::cout << ans << std::endl;
}