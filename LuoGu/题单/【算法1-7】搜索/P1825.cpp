/**
 * 	https://www.bilibili.com/video/BV1XP4y1f7sJ/
 */
#include <iostream>
#include <vector>
#include <queue>

int dxy[4][2]{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

struct BfsData
{
	int x;
	int y;
	int count;
};

struct Transmit
{
	int x1;
	int y1;
	int x2;
	int y2;
};

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
	int n, m;
	std::cin >> n >> m;
	
	int x0, y0;

	std::vector<std::vector<char>> grid(n, std::vector<char>(m));
	std::vector<Transmit> transmits('Z' + 1, Transmit{-1, -1, -1, -1});

	for (int i(0); i < n; ++i)
	{
		for (int j(0); j < m; ++j)
		{
			char& c(grid[i][j]);

			std::cin >> c;
			if (c == '@')
				x0 = i, y0 = j;
			if (isupper(c))
				if (transmits[c].x1 == -1)
					transmits[c].x1 = i,
					transmits[c].y1 = j;
				else
					transmits[c].x2 = i,
					transmits[c].y2 = j;
		}
	}

	std::queue<BfsData> bfs;
	bfs.push(BfsData{x0, y0, 0});
	grid[x0][y0] = '#';
	while (!bfs.empty())
	{
		BfsData bd(bfs.front());
		bfs.pop();

		for (int i(0); i < 4; ++i)
		{
			int x(bd.x + dxy[i][0]);
			int y(bd.y + dxy[i][1]);

			char& c(grid[x][y]);

			if (x < 0 || x >= n)
				continue;
			if (y < 0 || y >= m)
				continue;
			if (c == '#')
				continue;
			if (c == '.')
				bfs.push(BfsData{x, y, bd.count + 1}),
				c = '#';
			if (c == '=')
			{
				std::cout << bd.count + 1 << std::endl;
				return;
			}
			if (isupper(c))
				if (transmits[c].x1 == x && transmits[c].y1 == y)
					bfs.push(BfsData{transmits[c].x2, transmits[c].y2, bd.count + 1});
				else
					bfs.push(BfsData{transmits[c].x1, transmits[c].y1, bd.count + 1});
		}
	}
}