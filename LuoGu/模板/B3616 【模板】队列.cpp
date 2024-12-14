#include <iostream>
#include <cstdint>
#include <queue>

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
	int32_t n;
	std::cin >> n;
	std::queue<int32_t> q;
	while (n--)
	{
		int32_t mod;
		std::cin >> mod;
		if (mod == 1)
		{
			int32_t x;
			std::cin >> x;
			q.push(x);
		}
		else if (mod == 2)
		{
			if (q.empty())
				std::cout << "ERR_CANNOT_POP" << std::endl;
			else
				q.pop();
		}
		else if (mod == 3)
		{
			if (q.empty())
				std::cout << "ERR_CANNOT_QUERY" << std::endl;
			else
				std::cout << q.front() << std::endl;
		}
		else if (mod == 4)
		{
			std::cout << q.size() << std::endl;
		}
	}
}