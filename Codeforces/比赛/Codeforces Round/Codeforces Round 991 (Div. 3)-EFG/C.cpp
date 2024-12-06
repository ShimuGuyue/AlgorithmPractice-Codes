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
	int sum(0);
	int count2(0), count3(0);
	for (char c : s)
	{
		int a(c - '0');
		sum += a;
		if (a == 2)
			++count2;
		else if (a == 3)
			++count3;
	}

	if (sum % 9 == 0)
	{
		std::cout << "YES" << std::endl;
		return;
	}
	int flag(9 - sum % 9);
	if (flag == 1) // 10
	{
		if (count2 >= 5)	
			std::cout << "YES" << std::endl;
		else if (count2 >= 2 && count3)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	else if (flag == 2)
	{
		if (count2)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	else if (flag == 3) // 12
	{
		if (count2 >= 6)
			std::cout << "YES" << std::endl;
		else if (count2 >= 3 && count3)
			std::cout << "YES" << std::endl;
		else if (count3 >= 2)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	else if (flag == 4)
	{
		if (count2 >= 2)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	else if (flag == 5) // 14
	{
		if (count2 >= 7)
			std::cout << "YES" << std::endl;
		else if (count2 >= 4 && count3)
			std::cout << "YES" << std::endl;
		else if (count2 && count3 >= 2)
			std::cout << "YES" << std::endl;
		else 
			std::cout << "NO" << std::endl;
	}
	else if (flag == 6)
	{
		if (count2 >= 3)
			std::cout << "YES" << std::endl;
		else if (count3)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	else if (flag == 7) // 16
	{
		if (count2 >= 8)
			std::cout << "YES" << std::endl;
		else if (count2 >= 5 && count3)
			std::cout << "YES" << std::endl;
		else if (count2 >= 2 && count3 >= 2)
			std::cout << "YES" << std::endl;
		else 
			std::cout << "NO" << std::endl;

	}
	else if (flag == 8)
	{
		if (count2 >= 4)
			std::cout << "YES" << std::endl;
		else if (count2 && count3)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

}

/**
 * 	1	2	3
 * 	1	4	9
 * 	0  +2  +6
 * 
 * 	2 4 6 8 10 12 14
 */