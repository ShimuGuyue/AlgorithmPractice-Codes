#include <iostream>
#include <vector>
#include <algorithm>

struct Time
{
	int l;
	int r;
};

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
    int n, s, m;
	std::cin >> n >> s >> m;
	std::vector<Time> times(n + 2);
	times.front() = { 0, 0 };
	for (int i(1); i <= n; ++i)
	{
		std::cin >> times[i].l >> times[i].r;
	}
	times.back() = { m, m };
	for (int i(0); i < n + 1; ++i)
	{
		if (times[i + 1].l - times[i].r >= s)
		{
			std::cout << "YES" << std::endl;
			return;
		}
	}
	std::cout << "NO" << std::endl;
}