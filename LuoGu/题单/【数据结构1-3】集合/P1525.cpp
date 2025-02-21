//  $$$$$$\  $$\   $$\     $$\  $$$$$$\  $$$$$$\  $$$$$$\  
// $$  __$$\ $$ |  \$$\   $$  |$$  __$$\ \_$$  _|$$  __$$\ 
// $$ /  $$ |$$ |   \$$\ $$  / $$ /  \__|  $$ |  $$ /  $$ |
// $$$$$$$$ |$$ |    \$$$$  /  \$$$$$$\    $$ |  $$$$$$$$ |
// $$  __$$ |$$ |     \$$  /    \____$$\   $$ |  $$  __$$ |
// $$ |  $$ |$$ |      $$ |    $$\   $$ |  $$ |  $$ |  $$ |
// $$ |  $$ |$$$$$$$$\ $$ |    \$$$$$$  |$$$$$$\ $$ |  $$ |
// \__|  \__|\________|\__|     \______/ \______|\__|  \__|
// 您是否赞同纯美女神爱莉希雅的美貌盖世无双？【愛門】!
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
using std::pair;
using std::string;
using std::to_string;
using std::vector;
using std::deque;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::bitset;
using std::lower_bound;
using std::upper_bound;
using std::sort;
using std::max_element;
using std::min_element;

/*----------------------------------struct----------------------------------*/

struct Relative
{
	int u;
	int v;
	int aggro;
};

struct DisjointSet
{
	vector<int> fathers;

	DisjointSet(int n) : fathers(2 * n + 1)
	{
		for (int i = 1; i <= 2 * n; ++i)
		{
			fathers[i] = i;
		}
	}

	int Find(int x)
	{
		return fathers[x] == x ? x : fathers[x] = Find(fathers[x]);
	}

	void Merge(int x, int y)
	{
		fathers[Find(y)] = Find(x);
	}
};

/*-----------------------------------head-----------------------------------*/

void Solve(void);

/*-----------------------------------main-----------------------------------*/

int main(void)
{
	#ifdef Shimu_Guyue
		freopen("test.in" , "r", stdin );
		freopen("test.out", "w", stdout);
	#else
	#endif

    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
	// cin >> t;
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
	int n, m;
	cin >> n >> m;
	vector<Relative> relatives(m);
	for (auto &re : relatives)
	{
		cin >> re.u >> re.v >> re.aggro;
	}
	sort(relatives.begin(), relatives.end(),
	[](Relative a, Relative b)
	{
		return a.aggro > b.aggro;
	});

	DisjointSet ds(n);
	int ans = 0;
	for (Relative re : relatives)
	{
		if (ds.Find(re.u) == ds.Find(re.v))
		{
			ans = re.aggro;
			break;
		}

		ds.Merge(re.u, re.v + n);
		ds.Merge(re.v, re.u + n);
	}
	cout << ans << endl;
}