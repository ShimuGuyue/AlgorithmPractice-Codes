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

void Dfs(int node, int last, int &ans, vector<int> &sums, vector<vector<int>> &edges, int k);
void Solve(void);

/*-----------------------------------main-----------------------------------*/

int main(void)
{
#pragma region
	#ifdef Shimu_Guyue
		freopen("test.in" , "r", stdin );
		freopen("test.out", "w", stdout);
	#endif

    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> edges(n + 1);
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	int l = 0, r = n;
	while (l < r)
	{
		int mid = (l + r) / 2;
		int count = 0;
		vector<int> sums(n + 1, 1);
		Dfs(1, 0, count, sums, edges, mid);
		if (count > k)
			l = mid + 1;
		else
			r = mid;
	}
	int ans = r;
	cout << ans << endl;
}

void Dfs(int node, int last, int &count, vector<int> &sums, vector<vector<int>> &edges, int m)
{
	for (int i : edges[node])
	{
		if (i == last)
			continue;
		Dfs(i, node, count, sums, edges, m);
		sums[node] += sums[i];
	}

	if (sums[node] > m)
	{
		++count;
		sums[node] = 0;
	}
}