#include <iostream>

const int64_t mod(1e9 + 7);

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
    int64_t n;
    std::cin >> n;
    if (n == 2)
    {
        std::cout << 20 << std::endl; // (1 + 2 + 3 + 4) * 2
        return;
    }
    int64_t ans1(20);
    int64_t ans2;
    int64_t ans3;
    {
        int64_t m, a, b;
        m = (n - 2) * 4 % mod;
        a = 5;
        b = (n - 1) * 4 % mod;
        ans2 = 3 * m * (a + b) / 2 % mod;
    }
    {
        int64_t m, a, b;
        m = (n - 2) * (n - 2) % mod;
        a = ((n - 1) * 4 + 1) % mod;
        b = n * n % mod;
        ans3 = 4 * m * (a + b) / 2 % mod;
    }
    int64_t ans((ans1 + ans2 + ans3) % mod);
    std::cout << ans << std::endl;
}