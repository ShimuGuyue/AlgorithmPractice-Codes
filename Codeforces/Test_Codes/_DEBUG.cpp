#include <iostream>
#include <ctime>

void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	// freopen(".in.in"  , "r", stdin );
	// freopen(".out.out", "w", stdout);
	
	freopen(".in.in"  , "w", stdout );
	#endif

	srand(time(0));

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
	std::cout << 1 << std::endl;
	int n(rand() % 100 + 1);
	std::cout << n << std::endl;
	for (int i(0); i < n; ++i)
	{
		int a(rand() % 200 - 100);
		std::cout << a << " ";
	}
	std::cout << std::endl;
	for (int i(0); i < n; ++i)
	{
		int a(rand() % 200 - 100);
		std::cout << a << " ";
	}
	std::cout << std::endl;
}