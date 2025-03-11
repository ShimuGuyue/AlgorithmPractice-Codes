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

#pragma region

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
/*----------------------------------struct----------------------------------*/

/*-----------------------------------head-----------------------------------*/

void Solve(void);

/*-----------------------------------main-----------------------------------*/

int main(void)
{
#pragma region
	#ifdef Shimu_Guyue
		freopen("test.in" , "r", stdin );
		freopen("test.out", "w", stdout);
	#else
	#endif

    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	#define endl '\n'
#pragma endregion

    int t = 1;
	// cin >> t;
	// cout << endl;
	while (t--)
	{ 
		Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}
/*-----------------------------------body-----------------------------------*/

void Solve(void)
{
	using Loc = pair<int, int>;
	const int mod = 1e9+7;
	int dx[] = {-1, 0, 0, 1};
	int dy[] = {0, -1, 1, 0};

	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (auto &s : grid)
	{
		cin >> s;
	}
	Loc s, t;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == 'S')
				s = {i, j};
			if (grid[i][j] == 'T')
				t = {i, j};
		}
	}

	vector<vector<int>> lens(n, vector<int>(m, -1));
	vector<vector<int>> dp(n, vector<int>(m));
	dp[s.first][s.second] = 1;
	lens[s.first][s.second] = 0;

	queue<Loc> bfs;
	bfs.push(s);
	while (bfs.size())
	{
		int x = bfs.front().first;
		int y = bfs.front().second;
		bfs.pop();

		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m)
				continue;
			if (grid[xx][yy] == '#')
				continue;
			dp[x][y] = (dp[x][y] + dp[xx][yy]) % mod;
		}
		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m)
				continue;
			if (grid[xx][yy] == '#')
				continue;
			if (lens[xx][yy] != -1)
				continue;
			bfs.push({xx, yy});
			lens[xx][yy] = lens[x][y] + 1;
		}
	}
	
	cout << dp[t.first][t.second] << endl;
}