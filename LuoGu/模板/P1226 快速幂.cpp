#include <iostream>
#include <cstdint>

int64_t Q_pow(int64_t base, int64_t n, int64_t mod);
void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
		freopen(".in.in"  , "r", stdin );
		freopen(".out.out", "w", stdout);
		#define RUN_TIME \
			std::clog << (clock() * 1.0 / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl;
	#else
		#define RUN_TIME
	#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int32_t t(1);
	//std::cin >> t;
	while (t--)
	{
		Solve();
		//std::cout << std::endl;
	}
	RUN_TIME
	return 0;
}

void Solve(void)
{
	int64_t a, b, p;
	std::cin >> a >> b >> p;
	std::cout << a << "^" << b << " mod " << p << "=" << Q_pow(a, b, p) << std::endl;
}


int64_t Q_pow(int64_t base, int64_t n, int64_t mod)
{
    int64_t ans(1);
    while (n)
    {
        if (n & 1) // n % 2 == 1
            ans = ans * base % mod;
        n >>= 1; // n /= 2 ;
        base = base * base % mod;
    }
    return ans;
}