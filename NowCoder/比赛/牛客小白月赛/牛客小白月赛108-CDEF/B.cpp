#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
		freopen(".in.in"  , "r", stdin );
		freopen(".out.out", "w", stdout);
	#else
		#define RUN_TIME
	#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t = 1;
	std::cin >> t;
	while (t--)
	{
		Solve();
		//std::cout << std::endl;
	}
	RUN_TIME
	return 0;
}

void Solve(void)
{
	std::string s;
	std::cin >> s;
	int n = s.size();
	std::vector<int64_t> digits(n);
	for (int i = 0; i < n; ++i)
	{
		digits[i] = s[i] - '0';
	}
	std::sort(digits.begin(), digits.end());
	do
	{
		int64_t flag = 0;
		for (int i : digits)
		{
			flag = flag * 10 + i;
		}
		if (flag % 4 == 0)
		{
			std::cout << "YES" << std::endl;
			return;
		}
	}
	while (std::next_permutation(digits.begin(), digits.end()));
	std::cout << "NO" << std::endl;
}