#include <iostream>
#include <vector>

int n;
std::vector<int> ans;

void Dfs(int sum, int min, std::vector<int> ans);

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
	// int n;
	std::cin >> n;
	// std::vector<int> ans;
	Dfs(0, 1, ans);
}

void Dfs(int sum, int min, std::vector<int> ans)
{
	if (sum == n)
	{
		for (int i(0); i < ans.size() - 1; ++i)
		{
			std::cout << ans[i] << "+";
		}
		std::cout << ans.back() << std::endl;
		return;
	}

	for (int i(min); i < n; ++i)
	{
		if (sum + i <= n)
		{
			ans.push_back(i);
			Dfs(sum + i, i, ans);
			ans.pop_back();
		}
	}
}