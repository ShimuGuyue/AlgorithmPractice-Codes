#include <iostream>
#include <vector>

void Solve(void);

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
		Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void Solve(void)
{
    int n;
	std::cin >> n;
	while (n--)
	{
		int64_t a, b, c, d;
		std::cin >> a >> b >> c >> d;
		int64_t am;
		int64_t bc(b * c);
		if (bc % d == 0)
			am = bc / d - 1;
		else
			am = bc / d;
		int64_t ans(a - am);
		std::cout << ans << " ";
	}
	std::cout << std::endl;
}