/* 奇奇怪怪的信息
运行超时10连重测中
rejudging
你的代码目前运行超时，但是有10次重测机会，10次重测之中，有通过即会变为AC
Your code is TLE at present, but there are 10 rejudge. Among the 10 rejudge, if one rejudge passes, then AC
*/
// 这份代码我提交了 9 次，结果分别是
// TLE TLE TLE TLE AC TLE TLE TLE TLE

#include <iostream>
#include <vector>
#include <map>

using loc = std::pair<int, int>;

void solve(void);

int main(void)
{
	int t(1);
	//std::cin >> t;
	while (t--)
	{
		solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve(void)
{
    int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<std::vector<std::string>> grid(n + 1, std::vector<std::string>(m + 1));
	std::map<std::string, loc> locs;
	std::map<std::string, int> counts;
	while (k--)
	{
		std::string str;
		int x, y;
		std::cin >> str >> x >> y;
		if (grid[x][y] == "")
		{
			grid[x][y] = str;
			locs[str] = {x, y};
			++counts[str];
		}
		else
		{
			std::string str1(grid[x][y]);
			if (str > str1)
			{
				grid[x][y] = str;
				locs[str] = {x, y};
				++counts[str];

				locs.erase(str1);
				counts.erase(str1);
			}
		}
	}

	int q;
	std::cin >> q;
	while (q--)
	{
		std::string str;
		char c;
		std::cin >> str >> c;

		if (!counts[str])
		{
			std::cout << "unexisted empire." << std::endl;
		}
		else if (c == 'W')
		{
			if (locs[str].first == 1)
			{
				std::cout << "out of bounds!" << std::endl;
			}
			else
			{
				int x(locs[str].first);
				int y(locs[str].second);
				if (grid[x - 1][y] == "") //未被占领
				{
					std::cout << "vanquish!" << std::endl;
					grid[x - 1][y] = str;
					locs[str] = { x - 1, y };
					++counts[str];
				}
				else if (grid[x - 1][y] == str) // 自家领土
				{
					locs[str] = { x - 1, y };
					std::cout << "peaceful." << std::endl;
				}
				else // 产生冲突
				{
					std::string str1(grid[x - 1][y]);
					if (counts[str] > counts[str1] || (counts[str] == counts[str1] && str > str1))
					{
						locs[str] = { x - 1, y };
						counts[str] += counts[str1];
						counts.erase(str1);
						for (std::vector<std::string>& vs : grid)
						{
							for (std::string& s : vs)
							{
								if (s == str1)
									s = str;
							}
						}
						std::cout << str << " wins!" << std::endl;;
					}
					else if (counts[str] < counts[str1] || (counts[str] == counts[str1] && str < str1))
					{
						counts[str1] += counts[str];
						counts.erase(str);
						for (std::vector<std::string>& vs : grid)
						{
							for (std::string& s : vs)
							{
								if (s == str)
									s = str1;
							}
						}
						std::cout << str1 << " wins!" << std::endl;
					}
				}
			}
		}
		else if (c == 'A')
		{
			if (locs[str].second == 1)
			{
				std::cout << "out of bounds!" << std::endl;
			}
			else
			{
				int x(locs[str].first);
				int y(locs[str].second);
				if (grid[x][y - 1] == "") //未被占领
				{
					std::cout << "vanquish!" << std::endl;
					grid[x][y - 1] = str;
					locs[str] = { x, y - 1 };
					++counts[str];
				}
				else if (grid[x][y - 1] == str) // 自家领土
				{
					locs[str] = { x, y - 1 };
					std::cout << "peaceful." << std::endl;
				}
				else // 产生冲突
				{
					std::string str1(grid[x][y - 1]);
					if (counts[str] > counts[str1] || (counts[str] == counts[str1] && str > str1))
					{
						locs[str] = { x, y - 1 };
						counts[str] += counts[str1];
						counts.erase(str1);
						for (std::vector<std::string>& vs : grid)
						{
							for (std::string& s : vs)
							{
								if (s == str1)
									s = str;
							}
						}
						std::cout << str << " wins!" << std::endl;
					}
					else if (counts[str] < counts[str1] || (counts[str] == counts[str1] && str < str1))
					{
						counts[str1] += counts[str];
						counts.erase(str);
						for (std::vector<std::string>& vs : grid)
						{
							for (std::string& s : vs)
							{
								if (s == str)
									s = str1;
							}
						}
						std::cout << str1 << " wins!" << std::endl;
					}
				}
			}
		}
		else if (c == 'S')
		{
			if (locs[str].first == n)
			{
				std::cout << "out of bounds!" << std::endl;
			}
			else
			{
				int x(locs[str].first);
				int y(locs[str].second);
				if (grid[x + 1][y] == "") //未被占领
				{
					std::cout << "vanquish!" << std::endl;
					grid[x + 1][y] = str;
					locs[str] = { x + 1, y };
					++counts[str];
				}
				else if (grid[x + 1][y] == str) // 自家领土
				{
					locs[str] = { x + 1, y };
					std::cout << "peaceful." << std::endl;
				}
				else // 产生冲突
				{
					std::string str1(grid[x + 1][y]);
					if (counts[str] > counts[str1] || (counts[str] == counts[str1] && str > str1))
					{
						locs[str] = { x + 1, y };
						counts[str] += counts[str1];
						counts.erase(str1);
						for (std::vector<std::string>& vs : grid)
						{
							for (std::string& s : vs)
							{
								if (s == str1)
									s = str;
							}
						}
						std::cout << str << " wins!" << std::endl;
					}
					else if (counts[str] < counts[str1] || (counts[str] == counts[str1] && str < str1))
					{
						counts[str1] += counts[str];
						counts.erase(str);
						for (std::vector<std::string>& vs : grid)
						{
							for (std::string& s : vs)
							{
								if (s == str)
									s = str1;
							}
						}
						std::cout << str1 << " wins!" << std::endl;
					}
				}
			}
		}
		else if (c == 'D')
		{
			if (locs[str].second == m)
			{
				std::cout << "out of bounds!" << std::endl;
			}
			else
			{
				int x(locs[str].first);
				int y(locs[str].second);
				if (grid[x][y + 1] == "") //未被占领
				{
					std::cout << "vanquish!" << std::endl;
					grid[x][y + 1] = str;
					locs[str] = { x, y + 1 };
					++counts[str];
				}
				else if (grid[x][y + 1] == str) // 自家领土
				{
					locs[str] = { x, y + 1 };
					std::cout << "peaceful." << std::endl;
				}
				else // 产生冲突
				{
					std::string str1(grid[x][y + 1]);
					if (counts[str] > counts[str1] || (counts[str] == counts[str1] && str > str1))
					{
						locs[str] = { x, y + 1 };
						counts[str] += counts[str1];
						counts.erase(str1);
						for (std::vector<std::string>& vs : grid)
						{
							for (std::string& s : vs)
							{
								if (s == str1)
									s = str;
							}
						}
						std::cout << str << " wins!" << std::endl;
					}
					else if (counts[str] < counts[str1] || (counts[str] == counts[str1] && str < str1))
					{
						counts[str1] += counts[str];
						counts.erase(str);
						for (std::vector<std::string>& vs : grid)
						{
							for (std::string& s : vs)
							{
								if (s == str)
									s = str1;
							}
						}
						std::cout << str1 << " wins!" << std::endl;
					}
				}
			}
		}
	}
}