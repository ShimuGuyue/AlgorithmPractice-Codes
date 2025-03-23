#include <iostream>

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
    std::string s;
	std::cin >> s;
	std::cout << s[1] << s[2] << s[0] << " ";
	std::cout << s[2] << s[0] << s[1] << std::endl;
}