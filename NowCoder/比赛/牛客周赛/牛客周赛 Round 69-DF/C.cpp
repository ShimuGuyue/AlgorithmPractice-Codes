#include <iostream>

int64_t Gcd(int64_t a, int64_t b);
void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif

    // 关闭输入输出缓存，使效率提升
    std::ios::sync_with_stdio(false);
    // 解除cin和cout的默认绑定，来降低IO的负担使效率提升
    std::cin.tie(NULL); std::cout.tie(NULL);

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
    int64_t n, h;
	std::cin >> n >> h;
	while (n--)
	{
		int64_t x, y, z;
		std::cin >> x >> y >> z;
		int64_t a(x), b(y), c(h * 2 - z);
		int64_t gcd(Gcd(Gcd(a, b), c));
		a /= gcd; b /= gcd; c /= gcd;
		std::cout << a << " " << b << " " << c << std::endl;
	}
}

int64_t Gcd(int64_t a, int64_t b)
{
    if (a % b == 0)
        return b;
    return Gcd(b, a % b);
}