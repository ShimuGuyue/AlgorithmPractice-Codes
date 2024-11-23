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
	int x;
	std::cin >> x;
	std::cout << x << std::endl;
	for (int i(x); i > 1; --i)
	{
		int temp(x);
		int flag(0);
		while (temp % i == 0)
		{
			temp /= i;
			++flag;
		}
		if (temp == 1)
			std::cout << "=" << i << "^" << flag << std::endl;
	}
} 