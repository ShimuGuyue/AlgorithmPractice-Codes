#include <iostream>
#include <cstdint>
#include <vector>

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

    int32_t t = 1;
	std::cin >> t;
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
	std::string n;
	std::cin >> n;
	int32_t count = 0;
	std::vector<int32_t> anss;
	int32_t flag = 1;
	for (int32_t i = 1; i <= n.size(); ++i)
	{
		flag *= 10;
		char c = n[n.size() - i];
		if (c == '0')
			continue;
		++count;
		anss.push_back((c - '0') * flag / 10);
	}
	std::cout << count << std::endl;
	for (int32_t ans : anss)
	{
		std::cout << ans << " ";
	}
	std::cout << std::endl;
}