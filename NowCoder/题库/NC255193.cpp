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
    int64_t n, m, a, b;
    std::cin >> n >> m >> a >> b;
    int64_t ans(0);
    int64_t countA(0);
    while (1)
    {
        int64_t flag(countA * a);
        int64_t nn(n - countA * 2);
        int64_t mm(m - countA);
        if (nn < 0 || mm < 0)
            break;
        flag += std::min(nn, mm / 2) * b;
        ans = std::max(flag, ans);
        
        ++countA;
    }
    std::cout << ans << std::endl;
}