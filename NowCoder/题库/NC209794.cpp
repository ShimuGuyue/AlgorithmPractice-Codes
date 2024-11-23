#include <iostream>
#include <iomanip>
#include <cmath>

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
    double n;
    std::cin >> n;
    double ans(pow(n, 1.0 / 3) * 3);
    std::cout << std::fixed << std::setprecision(3) << ans << std::endl;
}