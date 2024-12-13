#include <iostream>
#include <vector>
#include <set>

int n, m;
std::vector<int> sets;
std::vector<std::vector<int>> relations; 

void Dfs(int node, int set);
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

	while (std::cin >> n >> m)
	{
		Solve();
		//std::cout << std::endl;
	}
	RUN_TIME
	return 0;
}

void Solve(void)
{
	sets = std::vector<int>(n + 1);
	for (int i(1); i <= n; ++i)
	{
		sets[i] = i;
	}
	relations = std::vector<std::vector<int>>(n + 1);

	while (m--)
	{
		int i, j;
		std::cin >> i >> j;
		relations[i].push_back(j);
		relations[j].push_back(i);
	}

	for (int i(1); i <= n; ++i)
	{
		if (sets[i] < i)
			continue;
		Dfs(i, i);
	}

	std::set<int> counts;
	for (int i(1); i <= n; ++i)
	{
		counts.insert(sets[i]);
	}
	std::cout << counts.size() - 1 << std::endl;
}

void Dfs(int node, int set)
{
	for (int i : relations[node])
	{
		if (sets[i] == set)
			continue;
		sets[i] = set;
		Dfs(i, set);
	}
}