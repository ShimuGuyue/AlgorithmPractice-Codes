#include <iostream>

void solve(void);

int main(void)
{
	int t(1);
	std::cin >> t;
	while (t--)
	{
		solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve(void)
{
    int64_t n;
	std::cin >> n;

	if (n == 1 || n == 2)
	{
		std::cout << 1 << std::endl;
		return;
	}

	for (int64_t ans(2); ; ans *= 2)
	{
		if (ans >= n)
		{
			std::cout << ans << std::endl;
			return;
		}
	}
}