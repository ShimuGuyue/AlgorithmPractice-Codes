#include <iostream>
#include <vector>

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
    int n, m;
	std::cin >> n >> m;
	std::vector<std::string> ss(n);
	for (int i(0); i < n; ++i)
	{
		std::cin >> ss[i];
	}
	int ans(0);
	for (int i(0); i < n; ++i)
	{
		if (ss[i].size() <= m)
		{
			m -= ss[i].size();
			++ans;
		}
		else
		{
			ans = i;
			break;
		}
	}
	std::cout << ans << std::endl;
}