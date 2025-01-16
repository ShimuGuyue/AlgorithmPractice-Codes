#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
using std::pair;
using std::string;
using std::vector;
using std::deque;
using std::queue;
using std::stack;
using std::set;
using std::map;
using std::sort;
using std::max_element;
using std::min_element;

void Build(int i, int j, int x, int y, int length, int count, char flag, vector<vector<char>> & grid, set<pair<int, int>> &delete_nodes);
void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
		freopen("test.in" , "r", stdin );
		freopen("test.out", "w", stdout);
	#else
		#define RUN_TIME
	#endif

    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
	// cin >> t;
	while (t--)
	{
		Solve();
		// cout << endl;
	}
	RUN_TIME
	return 0;
}

void Solve(void)
{
	int m, n;
	cin >> m >> n;
	set<pair<int, int>> delete_nodes;
	while (n--)
	{
		int i, j;
		cin >> i >> j;
		delete_nodes.insert(pair<int, int>{i, j});
	}
	int k = 5;
	for (int i = 3; i <= m; ++i)
	{
		k = k * 2 + 1;
	}
	vector<vector<char>> grid(k / 2 + 1, vector<char>(k, ' '));
	Build(1, 1, 0, k / 2, k / 2, k / 2, ' ', grid, delete_nodes);
	for (vector<char> vc : grid)
	{
		for (char c : vc)
		{
			cout << c;
		}
		cout << endl;
	}
}

void Build(int i, int j, int x, int y, int length, int count, char flag, vector<vector<char>> & grid, set<pair<int, int>> &delete_nodes)
{
	if (x == grid.size())
		return;

	if (count == length)
	{
		grid[x][y] = 'o';
		if (delete_nodes.find(pair<int, int>{i + 1, j * 2 - 1}) == delete_nodes.end())
		{	// 左子树
			Build(i + 1, j * 2 - 1, x + 1, y - 1, length / 2, 0, '/', grid, delete_nodes);
		}
		if (delete_nodes.find(pair<int, int>{i + 1, j * 2}) == delete_nodes.end())
		{	// 右子树
			Build(i + 1, j * 2    , x + 1, y + 1, length / 2, 0, '\\', grid, delete_nodes);
		}
	}
	else
	{
		grid[x][y] = flag;
		if (flag == '/')
		{
			Build(i, j, x + 1, y - 1, length, count + 1, '/', grid, delete_nodes);
		}
		else if (flag == '\\')
		{
			Build(i, j, x + 1, y + 1, length, count + 1, '\\', grid, delete_nodes);
		}
	}
}