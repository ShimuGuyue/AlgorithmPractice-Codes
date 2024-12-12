#include <iostream>
#include <vector>

int n, m, p;
std::vector<int> sets;
std::vector<std::vector<int>> relatives;

void Dfs(int node, int set);
void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
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
	return 0;
}

void Solve(void)
{
	// int n, m, p;
	std::cin >> n >> m >> p;

	// std::vector<int> sets(n + 1);
	sets = std::vector<int>(n + 1);
	// std::vector<std::vector<int>> relatives(n + 1);
	relatives = std::vector<std::vector<int>>(n + 1);
	for (int i(1); i <= n; ++i)
	{
		sets[i] = i;
	}

	while (m--)
	{
		int i, j;
		std::cin >> i >> j;
		relatives[i].push_back(j);
		relatives[j].push_back(i);
	}
	for (int i(1); i <= n; ++i)
	{
		if (sets[i] != i)
			continue;
		Dfs(i, i);
	}

	while (p--)
	{
		int i, j;
		std::cin >> i >> j;
		if (sets[i] == sets[j])
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
	}
}

void Dfs(int node, int set)
{
	for (int next : relatives[node])
	{
		if (sets[next] == set)
			continue;
		sets[next] = set;
		Dfs(next, set);
	}
}