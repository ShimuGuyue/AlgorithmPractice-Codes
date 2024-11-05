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
    int64_t x;
    std::cin >> x;
    int mod(x * 10 % 7);
    std::cout << x << 7 - mod << std::endl;
}