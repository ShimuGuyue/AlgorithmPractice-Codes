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
    int64_t n;
    std::cin >> n;
    if (n % 3)
        std::cout << n / 3 * 2 << std::endl;
    else
        std::cout << n / 3 - 1 << std::endl;
}