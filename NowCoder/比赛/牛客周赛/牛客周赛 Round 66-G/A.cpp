#include <iostream>

namespace solve
{
	void Solve(void);
}

int main(void)
{
	int t(1);
	//std::cin >> t;
	while (t--)
	{
		solve::Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve::Solve(void)
{
    int a, b, c;
	std::cin >> a >> b >> c;
	if (a > b)
		std::swap(a, b);
	if (a > c)
		std::swap(a, c);
	if (b > c)
		std::swap(b, c);
	std::cout << std::max(a + b, c) << std::endl;;
}