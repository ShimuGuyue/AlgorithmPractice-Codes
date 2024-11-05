// 一共就那么些限制条件
#include <iostream>

void solve(void);

int main(void)
{
	int t(1);
	std::cin >> t;
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
	std::string s1;
	std::string s2;
	int mode(1);
	for (char c : s)
	{
		if (mode == 1)
		{
			if (c == '@')
				mode = 2;
			else
				s1 += c;
		}
		else
		{
			s2 += c;
		}
	}

	if (s1.empty() || s2.empty())
	{
		std::cout << "No" << std::endl;
		return;
	}

	if (s1.size() > 64 || s2.size() > 255)
	{
		std::cout << "No" << std::endl;
		return;
	}

	if (s1.front() == '.' || s1.back() == '.')
	{
		std::cout << "No" << std::endl;
		return;
	}

	if (s2.front() == '.' || s2.back() == '.')
	{
		std::cout << "No" << std::endl;
		return;
	}

	if (s2.front() == '-' || s2.back() == '-')
	{
		std::cout << "No" << std::endl;
		return;
	}

	for (char c : s1)
	{
		if (!isalpha(c) && !isdigit(c) && c != '.')
		{
			std::cout << "No" << std::endl;
			return;
		}
	}

	for (char c : s2)
	{
		if (!isalpha(c) && !isdigit(c) && c != '.' && c != '-')
		{
			std::cout << "No" << std::endl;
			return;
		}
	}

	std::cout << "Yes" << std::endl;
}