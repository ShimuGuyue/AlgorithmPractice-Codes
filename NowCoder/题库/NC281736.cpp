#include <iostream>

void Solve(void);

int main(void)
{
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
    int n, a, b;
	std::cin >> n >> a >> b;
	int ans(n / std::min(a, b));
	std::cout << ans << std::endl;
}