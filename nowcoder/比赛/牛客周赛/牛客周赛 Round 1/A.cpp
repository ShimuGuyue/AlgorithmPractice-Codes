#include <iostream>

void solve(void);

int main(void)
{
	int t(1);
	//std::cin >> t;
	while (t--)
	{
		solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve(void)
{
    int n;
	std::cin >> n;
	for (int i(1); i <= n * 3; ++i)
	{
		for (int j(1); j <= n; ++ j)
		{
			std::cout << "*";
		}
		for (int j(1); j <= n * 2; ++ j)
		{
			std::cout << ".";
		}
		for (int j(1); j <= n; ++ j)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	for (int i(1); i <= 3; ++i)
	{
		for (int j(1); j <= i; ++j)
		{
			std::cout << ".";
		}
		for (int j(1); j <= n; ++j)
		{
			std::cout << "*";
		}
		for (int j(i + 1); j <= n; ++j)
		{
			std::cout << ".";
		}
		for (int j(i + 1); j <= n; ++j)
		{
			std::cout << ".";
		}
		for (int j(1); j <= n; ++j)
		{
			std::cout << "*";
		}
		for (int j(1); j <= i; ++j)
		{
			std::cout << ".";
		}
		std::cout << std::endl;
	}
}