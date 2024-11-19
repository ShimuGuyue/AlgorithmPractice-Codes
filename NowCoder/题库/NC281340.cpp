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
    int a, b, c, d;
	std::cin >> a >> b >> d >> c;
	int flag(0);
	int temp;

	temp = std::min(a, b);
	flag = (flag + temp) % 2;
	a -= temp;
	b -= temp;

	temp = std::min(b, c);
	flag = (flag + temp) % 2;
	b -= temp;
	c -= temp;

	temp = std::min(c, d);
	flag = (flag + temp) % 2;
	c -= temp;
	d -= temp;

	temp = std::min(d, a);
	flag = (flag + temp) % 2;
	d -= temp;
	a -= temp;

	if (flag)
		std::cout << "kou" << std::endl;
	else
		std::cout << "yukari" << std::endl;
} 