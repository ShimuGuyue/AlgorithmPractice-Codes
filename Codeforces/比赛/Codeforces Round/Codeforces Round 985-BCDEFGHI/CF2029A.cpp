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
    int l, r, k;
	std::cin >> l >> r >> k;
	if (r / k < l)
		std::cout << 0 << std::endl;
	else
		std::cout << r / k - l + 1 << std::endl; 
}