#include <iostream>

void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif
	
	int t(1);
	std::cin >> t;
	while (t--)
	{
		Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void Solve(void)
{
	int64_t l1, r1, l2, r2;
	std::cin >> l1 >> r1 >> l2 >> r2;
	std::string min(std::to_string(l1 + l2));
	std::string max(std::to_string(r1 + r2));
	int ans(0);
	if (min.size() < max.size())
	{
		ans += max[0] - 1 - '0';
		int n(max.size());
		bool all9(true);
		for (int i(1); i < n; ++i)
		{
			ans += 9;
			if (max[i] != '9')
				all9 = false;
		}
		if (all9)
			++ans;
	}
	else
	{
		int n(max.size());
		for (int i(0); i < n; ++i)
		{
			if (min[i] == max[i])
			{
				ans += min[i] - '0';
			}
			else
			{
				bool all9(true);
				ans += max[i] - 1 - '0';
				for (int j(i + 1); j < n; ++j)
				{
					ans += 9;
					if (max[j] != '9')
						all9 = false;
				}
				if (all9)
					++ans;
				break;
			}
		}
	}
	std::cout << ans << std::endl;
}