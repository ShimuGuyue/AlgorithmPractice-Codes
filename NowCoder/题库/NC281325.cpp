#include <iostream>

void solve(void);

int main(void)
{
	int t(1);
	//std::cin >> t;
	while (t--)
	{
		solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve(void)
{
    std::string s;
	std::cin >> s;
	for (char& c : s)
	{
		c = tolower(c);
	}
	if (s == "yes")
		std::cout << "accept" << std::endl;
	else
		std::cout << "wrong answer" << std::endl;
} 