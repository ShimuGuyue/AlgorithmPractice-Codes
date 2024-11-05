#include <iostream>
#include <vector>
#include <set>

void solve(void);

int main(void)
{
	int t(1);
	// std::cin >> t;
	while (t--)
	{
		solve();
		// std::cout << std::endl;
	}
	return 0;
}

void solve(void)
{
	int64_t a, b;
	std::cin >> a >> b;

	std::vector<int64_t> factorOfAs;
	std::vector<int64_t> factorOfBs;
	std::set<int64_t> anss;
	
	// 求出 a 和 b 的所有因子
	for (int i(1); i * i <= a; ++i)
	{
		if (a % i == 0)
		{
			factorOfAs.push_back(i);
			if (i * i != a)
			{
				factorOfAs.push_back(a / i);
			}
		}
	}
	for (int i(1); i * i <= b; ++i)
	{
		if (b % i == 0)
		{
			factorOfBs.push_back(i);
			if (i * i != b)
			{
				factorOfBs.push_back(b / i);
			}
		}
	}

	// a b 所有因子分别相乘
	for (int64_t facA : factorOfAs)
	{
		for (int64_t facB : factorOfBs)
		{
			anss.insert(facA * facB);
		}
	}

	std::cout << anss.size() << std::endl;
	for (int64_t ans : anss)
	{
		std::cout << ans << " ";
	}
	std::cout << std::endl;
}