#include <iostream>

namespace solve
{
	void Solve(void);
}

int main(void)
{
	int t(1);
	std::cin >> t;
	while (t--)
	{
		solve::Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve::Solve(void)
{
    int n;
	std::cin >> n;
	for (int i(n); i > 0; --i)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}