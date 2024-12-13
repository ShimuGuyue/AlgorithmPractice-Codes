#include <iostream>
#include <vector>
#include <set>

#pragma GCC optimize(1)

void Init(int m, std::vector<std::vector<int>>& relations);
void Dfs(int node, int set, std::vector<int>& sets, std::vector<std::vector<int>>& relations);
void Merge(std::vector<int>& sets, std::vector<std::vector<int>>& relations);
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
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<int> sets(n);
	std::vector<std::vector<int>> relations(n);
	// sets = std::vector<int>(n);
	// relations = std::vector<std::vector<int>>(n);
	Init(m, relations);
	Merge(sets, relations);
	while (q--)
	{
		int i, j;
		std::cin >> i >> j;
		if (sets[i] == sets[j])
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
}

void Init(int m, std::vector<std::vector<int>>& relations) // 初始关系建图
{
    while (m--)
    {
        int i, j;
        std::cin >> i >> j;
        relations[i].push_back(j);
        relations[j].push_back(i);
    }
}

void Dfs(int node, int set, std::vector<int>& sets, std::vector<std::vector<int>>& relations)
{
	for (int next : relations[node])
	{
		if (sets[next] == set)
			continue;
		sets[next] = set;
		Dfs(next, set, sets, relations);
	}
}

void Merge(std::vector<int>& sets, std::vector<std::vector<int>>& relations)    // 集合合并
{
    int n(sets.size());
    for (int i(0); i < n; ++i)
    {
        if (sets[i] < i)    // 属于别人的集合
			continue;
		Dfs(i, i, sets, relations);  // 自己是集合首领
    }
}