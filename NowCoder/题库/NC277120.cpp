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
	std::string s;
	std::cin >> s;
	std::string digit;
	std::string upper;
	std::string lowwer;
	for (char c : s)
	{
		if (isdigit(c))
			digit += c;
		else if (isupper(c))
			upper += c;
		else 
			lowwer += c;
	}
	std::cout << lowwer << digit << upper << std::endl;
}