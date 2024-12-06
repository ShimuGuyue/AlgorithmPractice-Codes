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
    int n;
	std::cin >> n;
	int64_t sum0(0), sum1(0);
	for (int i(0); i < n; ++i)
	{
		int64_t a;
		std::cin >> a;
		if (i & 1)
			sum1 += a;
		else 
			sum0 += a;
	}
	int count1(n / 2);
	int count0(n - count1);
	if (sum0 % count0 || sum1 % count1)
	{
		std::cout << "NO" << std::endl;
		return;
	}
	if (sum0 / count0 == sum1 / count1)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
}
