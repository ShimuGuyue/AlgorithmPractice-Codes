#include <iostream>
#include <vector>
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
    int n, k;
	std::cin >> n >> k;
	std::vector<int> as(n);
	for (int i(0); i < n; ++i)
	{
		std::cin >> as[i];
	}
	if (n == 1)
	{
		int ans(as[0]);
		std::cout << ans << std::endl;
	}
	else if (n == 2)
	{
		int ans(as.front() + as.back());
		std::cout << ans << std::endl;
	}
	else if (k >= n - 2)
	{
		int ans(0);
		std::sort(as.begin(), as.end(),
			[](int a, int b)
			{
				return a > b;
			});
		ans = as[0] + as[1];
		std::cout << ans << std::endl;
	}
	else
	{
		int ans(0);
		int l(n - k - 1);
		std::vector<int> sum_max_l(n);
		sum_max_l.front() = as.front();
		for (int i(1); i < n; ++i)
		{
			sum_max_l[i] = std::max(sum_max_l[i - 1], as[i]);
		}
		std::vector<int> sum_max_r(n);
		sum_max_r.back() = as.back();
		for (int i(n - 2); i >= 0; --i)
		{
			sum_max_r[i] = std::max(sum_max_r[i + 1], as[i]);
		}
		for (int i(0); i + l < n; ++i)
		{
			ans = std::max(sum_max_l[i] + sum_max_r[i + l], ans);
		}
		std::cout << ans << std::endl;
	}
}