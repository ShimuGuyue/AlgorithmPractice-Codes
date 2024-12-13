#include <iostream>
#include <cstdint>
#include <stack>

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

    int t(1);
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
	int n;
	std::cin >> n;
	std::stack<uint64_t> k;
	while (n--)
	{
		std::string mod;
		std::cin >> mod;
		if (mod == "push")
		{
			uint64_t x;
			std::cin >> x;
			k.push(x);
		}
		else if (mod == "pop")
		{
			if (k.empty())
				std::cout << "Empty" << std::endl;
			else
				k.pop();
		}
		else if (mod == "query")
		{
			if (k.empty())
				std::cout << "Anguei!" << std::endl;
			else
				std::cout << k.top() << std::endl;
		}
		else if (mod == "size")
		{
			std::cout << k.size() << std::endl;
		}
	}
	
}