#pragma region
/*
/$$$$$$\  $$\   $$\     $$\  $$$$$$\  $$$$$$\  $$$$$$\  
$$  __$$\ $$ |  \$$\   $$  |$$  __$$\ \_$$  _|$$  __$$\ 
$$ /  $$ |$$ |   \$$\ $$  / $$ /  \__|  $$ |  $$ /  $$ |
$$$$$$$$ |$$ |    \$$$$  /  \$$$$$$\    $$ |  $$$$$$$$ |
$$  __$$ |$$ |     \$$  /    \____$$\   $$ |  $$  __$$ |
$$ |  $$ |$$ |      $$ |    $$\    $$|  $$ |  $$ |  $$ |
$$ |  $$ |$$$$$$$$\ $$ |    \$$$$$$  |$$$$$$\ $$ |  $$ |
\__|  \__|\________|\__|     \______/ \______|\__|  \__|
您是否赞同纯美女神爱莉希雅的美貌盖世无双？【愛門】!
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::fixed;
using std::setprecision;
using std::setw;
#include <cstdint>
#include <climits>
#include <cmath>
#include <utility>
using std::pair;
#include <string>
using std::string;
using std::to_string;
using std::stoi;
#include <vector>
using std::vector;
#include <deque>
using std::deque;
#include <list>
using std::list;
#include <stack>
using std::stack;
#include <queue>
using std::queue;
using std::priority_queue;
#include <set>
using std::set;
#include <map>
using std::map;
#include <bitset>
using std::bitset;
#include <algorithm>
using std::lower_bound;
using std::upper_bound;
using std::sort;
using std::max_element;
using std::min_element;

template <typename T>
std::istream& operator>>(std::istream &in, vector<T> &v)
{
	for (T &t : v) in >> t;
	return in;
}
template <typename T>
std::ostream& operator<<(std::ostream &out, vector<T> &v)
{
	for (T &t : v) out << t << " ";
	return out;
}
#pragma endregion

/*----------------------------------solve-----------------------------------*/

class HYS
{
public:
	struct Path
	{
		int x1, y1;
		int x2, y2;

		Path(int x1, int y1, int x2, int y2)
		{
			this->x1 = x1 + 1;
			this->x2 = x2 + 1;
			this->y1 = y1 + 1;
			this->y2 = y2 + 1;
		}
	};
	

	static void Solve(void)
	{
		int n, m;
		cin >> n >> m;
		vector<string> grid(n);
		cin >> grid;

		vector<Path> paths;
		for (int i = 0; i < n; ++i)
		{
			if (i & 1)
			{
				for (int j = m - 1; j > 0; --j)
				{
					if (grid[i][j] == '0')
					{
						Turn(grid, i, j - 1, i, j);
						paths.push_back(Path(i, j - 1, i, j));
					}
				}
				if (i != n - 1)
				{
					if (grid[i][0] == '0')
					{
						Turn(grid, i, 0, i + 1, 0);
						paths.push_back(Path(i, 0, i + 1, 0));
					}
				}
			}
			else
			{
				for (int j = 1; j < m; ++j)
				{
					if (grid[i][j - 1] == '0')
					{
						Turn(grid, i, j - 1, i, j);
						paths.push_back(Path(i, j - 1, i, j));
					}
				}
				if (i != n - 1)
				{
					if (grid[i][m - 1] == '0')
					{
						Turn(grid, i, m - 1, i + 1, m - 1);
						paths.push_back(Path(i, m - 1, i + 1, m - 1));
					}
				}
			}
		}

		if (grid[n - 1][m - 1] == '0' || grid[n - 1][0] == '0')
		{
			cout << -1 << endl;
			return;
		}
		cout << paths.size() << endl;
		for (auto &p : paths)
		{
			cout << p.x1 << " " << p.y1 << " " << p.x2 << " " << p.y2 << endl;
		}
	}

	static void Turn(vector<string> &grid, int x1, int y1, int x2, int y2)
	{
		if (grid[x1][y1] == '0')
			grid[x1][y1] = '1';
		else
			grid[x1][y1] = '0';
		if (grid[x2][y2] == '0')
			grid[x2][y2] = '1';
		else
			grid[x2][y2] = '0';
	}

	// static 

	// static 
};

/*-----------------------------------main-----------------------------------*/

int main(void)
{
	#ifdef Shimu_Guyue
		freopen( "in.test", "r", stdin );
		freopen("out.test", "w", stdout);
	#endif
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
	// cin >> t;
	while (t--)
	{ 
		HYS::Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}
