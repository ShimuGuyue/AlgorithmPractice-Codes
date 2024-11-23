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
    std::string a, b;
	std::cin >> a >> b;
	std::string a1, a2;
	std::string b1, b2;
	bool point_a(false);
	bool point_b(false);
	for (int i(0); i < a.size(); ++i)
	{
		if (point_a)
			if (a2.size() < 6)
				a2 += a[i];
			else;
		else
			if (a[i] == '.')
				point_a = true;
			else
				a1 += a[i];
	}
	for (int i(0); i < b.size(); ++i)
	{
		if (point_b)
			if (b2.size() < 6)
				b2 += b[i];
			else;
		else
			if (b[i] == '.')
				point_b = true;
			else
				b1 += b[i];
	}
	while (a2.size() < 6)
	{
		a2 += '0';
	}
	while (b2.size() < 6)
	{
		b2 += '0';
	}

	if (a1 == b1 && a2 == b2)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
}