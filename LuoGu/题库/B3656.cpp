/**
 * 	当不需要随机访问下标取元素时，为什么不试试用 list 呢
 */

#include <iostream>
#include <cstdint>
#include <vector>
#include <list>

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
	int32_t q;
	std::cin >> q;
	std::vector<std::list<int32_t>> ds; 
	while (q--)
	{
		std::string mod;
		std::cin >> mod;
		if (mod == "push_back")
		{
			int32_t a, x;
			std::cin >> a >> x;
			if (ds.size() <= a)
				ds.resize(a + 1);
			ds[a].push_back(x);
		}
		else if (mod == "pop_back")
		{
			int32_t a;
			std::cin >> a;
			if (ds.size() <= a)
				ds.resize(a + 1);
			if (!ds[a].empty())
				ds[a].pop_back();
		}
		else if (mod == "push_front")
		{
			int32_t a, x;
			std::cin >> a >> x;
			if (ds.size() <= a)
				ds.resize(a + 1);
			ds[a].push_front(x);
		}
		else if (mod == "pop_front")
		{
			int32_t a;
			std::cin >> a;
			if (ds.size() <= a)
				ds.resize(a + 1);
			if (!ds[a].empty())
				ds[a].pop_front();
		}
		else if (mod == "size")
		{
			int32_t a;
			std::cin >> a;
			if (ds.size() <= a)
				ds.resize(a + 1);
			std::cout << ds[a].size() << std::endl;
		}
		else if (mod == "front")
		{
			int32_t a;
			std::cin >> a;
			if (ds.size() <= a)
				ds.resize(a + 1);
			if (!ds[a].empty())
				std::cout << ds[a].front() << std::endl;
		}
		else if (mod == "back")
		{
			int32_t a;
			std::cin >> a;
			if (ds.size() <= a)
				ds.resize(a + 1);
			if (!ds[a].empty())
				std::cout << ds[a].back() << std::endl;
		}
	}
}