#include <iostream>
#include <map>

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
    int k;
	std::cin >> k;
	std::map<int, int> counts;
	for (int i(0); i < k; ++i)
	{
		int a;
		std::cin >> a;
		++counts[a];
	}
	for (std::map<int, int>::iterator it(counts.begin()); it != counts.end(); ++it)
	{
		std::map<int, int>::iterator jt(it);
		for ( ; jt != counts.end(); ++jt)
		{
			if (it->first == jt->first && it->second == 1)
				continue;
			if (it->first * jt->first == k - 2)
			{
				std::cout << it->first << " " << jt->first << std::endl;
				return;
			}
		}
	}
}