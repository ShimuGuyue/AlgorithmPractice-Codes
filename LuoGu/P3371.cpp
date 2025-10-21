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
using std::next_permutation;
#include <random>

std::mt19937 Rand(time(nullptr));

template <typename T, typename K>
std::istream& operator>>(std::istream &in, pair<T, K> &p)
{
	in >> p.first >> p.second;
	return in;
}
template <typename T, typename K>
std::ostream& operator<<(std::ostream &out, pair<T, K> &p)
{
	out << p.first << ' ' << p.second;
	return out;
}
template <typename T>
std::istream& operator>>(std::istream &in, vector<T> &v)
{
	for (T &t : v) in >> t;
	return in;
}
template <typename T>
std::ostream& operator<<(std::ostream &out, vector<T> &v)
{
	for (T &t : v) out << t << ' ';
	return out;
}
#pragma endregion

/*----------------------------------solve-----------------------------------*/

class HYS
{
public:
	static void Solve(void)
	{
		int n, m, s;
		cin >> n >> m >> s;
		vector<map<int, int>> grid(n + 1);
		for (int i = 0; i < m; ++i)
		{
			int u, v, w;
			cin >> u >> v >> w;
			if (grid[u].find(v) == grid[u].end())
				grid[u][v] = w;
			else
				grid[u][v] = std::min(grid[u][v], w);
		}

		vector<int> distances(n + 1, INT_MAX);
		vector<int> is_inqueue(n + 1, 0);
		distances[s] = 0;
		is_inqueue[s] = 1;
		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			is_inqueue[u] = 0;
			
			for (auto [v, w] : grid[u])
			{
				if (distances[u] + w < distances[v])
				{
					distances[v] = distances[u] + w;
					if (!is_inqueue[v])
					{
						q.push(v);
						is_inqueue[v] = 1;
					}
				}
			}
		}
		
		for (int i = 1; i <= n; ++i)
		{
			cout << distances[i] << " ";
		}
		cout << endl;
	}

	// static 

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
