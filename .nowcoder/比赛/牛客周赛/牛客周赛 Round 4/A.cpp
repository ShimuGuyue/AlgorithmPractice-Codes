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
    int n, k;
    std::cin >> n >> k;
    n -= k * 3;
    if (n < 0)
    {
        std::cout << -1 << std::endl;
        return;
    }
    while (k--)
    {
        std::cout << "you";
    }
    while (n--)
    {
        std::cout << "y";
    }
    std::cout << std::endl;
}