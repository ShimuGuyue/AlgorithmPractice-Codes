#include <iostream>
#include <vector>

void Solve(void);

int main(void)
{
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
    int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<char>> grid(n, std::vector<char>(m));
	for (std::vector<char>& vc : grid)
	{
		for (char& c : vc)
		{
			std::cin >> c;
		}
	}
	int ans(0);
	for (int i(1); i < n; ++i)
	{
		for (int j(1); j < m; ++j)
		{
			if (grid[i-1][j-1] == '.')
				continue;
			if (grid[i][j-1] == '.')
				continue;
			if (grid[i-1][j] == '.')
				continue;
			if (grid[i][j] == '.')
				continue;

			++ans;
		}
	}
	std::cout << ans << std::endl;
}