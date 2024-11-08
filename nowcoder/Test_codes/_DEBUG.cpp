#include <iostream>

namespace solve
{
	void Solve(void);
}

int main(void)
{
#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
#endif
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
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b;
}