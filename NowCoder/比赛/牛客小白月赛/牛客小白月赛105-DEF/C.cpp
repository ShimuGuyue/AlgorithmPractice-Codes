#include <iostream>
#include <vector>
#include <queue>

struct Point
{
	int x;
	int y;
};

void Bfs(std::vector<std::vector<char>>& grid, int x, int y, int l1, int l2, int r1, int r2, std::vector<Point>& points, bool& add);
void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen(".in.in", "r", stdin);
	freopen(".out.out", "w", stdout);
	#endif

	// 关闭输入输出缓存，使效率提升
	std::ios::sync_with_stdio(false);
	// 解除cin和cout的默认绑定，来降低IO的负担使效率提升
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t(1);
	// std::cin >> t;
	while (t--)
	{
		Solve();
		// std::cout << std::endl;
	}
	return 0;
}

void Solve(void)
{
	int n;
	std::cin >> n;
	std::vector<std::vector<char>> grid(2, std::vector<char>(n));
	for (int i(0); i < 2; ++i)
	{
		for (int j(0); j < n; ++j)
		{
			std::cin >> grid[i][j];
		}
	}


	int ans(0);
	
	for (int i(0); i < 2; ++i)
	{
		for (int j(0); j < n; ++j)
		{
			if (grid[i][j] == 'x')
				continue;

			int count_before(0);
			int count_after(0);
			int l1(0), l2(j == 0     ? 0     : j - 1);
			int r1(1), r2(j == n - 1 ? n - 1 : j + 1);

			std::vector<Point> points;
			for (int p(l1); p <= r1; ++p)
			{
				for (int q(l2); q <= r2; ++q)
				{
					if (grid[p][q] == 'x')
						continue;

					bool add = false;
					Bfs(grid, p, q, l1, l2, r1, r2, points, add);
					if (add)
						++count_before;
				}
			}

			points.clear();
			grid[i][j] = 'x';
			for (int p(l1); p <= r1; ++p)
			{
				for (int q(l2); q <= r2; ++q)
				{
					if (grid[p][q] == 'x')
						continue;				
					bool add = false;
					Bfs(grid, p, q, l1, l2, r1, r2, points, add);
					if (add)
						++count_after;
				}
			}
			grid[i][j] = '.';

			if (count_after != count_before)
				++ans;
		}
	} 

	std::cout << ans << std::endl;
}

void Bfs(std::vector<std::vector<char>>& grid, int x, int y, int l1, int l2, int r1, int r2, std::vector<Point>& points, bool& add)
{
	for (Point p : points)
	{
		if (p.x == x && p.y == y)
			return;
	}
	
	add = true;

	points.push_back({ x, y });

	std::queue<Point> next_points;
	if (x - 1 >= l1 && grid[x - 1][y] == '.')
		next_points.push({ x - 1, y });
	if (x + 1 <= r1 && grid[x + 1][y] == '.')
		next_points.push({ x + 1, y });
	if (y - 1 >= l2 && grid[x][y - 1] == '.')
		next_points.push({ x, y - 1 });
	if (y + 1 <= r2 && grid[x][y + 1] == '.')
		next_points.push({ x, y + 1 });
	while (!next_points.empty())
	{
		Point p = next_points.front();
		next_points.pop();
		Bfs(grid, p.x, p.y, l1, l2, r1, r2, points, add);
	}
}