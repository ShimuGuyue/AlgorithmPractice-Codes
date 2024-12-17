#include <iostream>
#include <vector>

bool Is_prime(int x);
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
    int n;
	std::cin >> n;
	if (n < 5)
	{
		std::cout << -1 << std::endl;
		return;
	}
	std::vector<int> anss;
	for (int i(1); i <= n; i += 2)
	{
		anss.push_back(i);
	}
	int flag1(n % 2 ? n : n - 1);
	int flag2(-1);
	for (int i(2); i <= n; i += 2)
	{
		if (!Is_prime(flag1 + i))
		{
			anss.push_back(i);
			flag2 = i;
			break;
		}
	}
	if (flag2 == -1)
	{
		std::cout << -1 << std::endl;
		return;
	}
	for (int i(2); i <= n; i += 2)
	{
		if (i == flag2)
			continue;
		anss.push_back(i);
	}
	for (int ans : anss)
	{
		std::cout << ans << " ";
	}
	std::cout << std::endl;
}

bool Is_prime(int x)
{
    if (x < 2)
        return false;
    for (int i(2); i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}