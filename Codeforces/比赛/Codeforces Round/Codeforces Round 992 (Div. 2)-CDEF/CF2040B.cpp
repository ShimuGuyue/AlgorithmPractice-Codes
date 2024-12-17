#include <iostream>

void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif
	
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

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
    int n;
	std::cin >> n;
	int ans(0);
	int flag(1);
	while (1)
	{
		++ans;
		if (flag >= n)
		{
			std::cout << ans << std::endl;
			return;
		}
		flag = flag * 2 + 2;
	}
}