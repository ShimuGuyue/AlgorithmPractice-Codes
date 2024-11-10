#include <iostream>
#include <string>

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
    std::string n;
	std::cin >> n;
	long long min(std::stoll(n));
	int m(n.size());
	while (m--)
	{
		std::string temp(n.begin() + 1, n.end());
		temp += n.front();
		min = std::min(min, std::stoll(temp));
		n = temp;
	}
	std::cout << min << std::endl;
}