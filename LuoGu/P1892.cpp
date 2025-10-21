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
using std::stoi;
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

struct DisjointSet
{
	vector<int> fathers;

	DisjointSet(int n) : fathers(n * 2 + 1)
	{
		for (int i = 1; i <= n * 2; ++i)
		{
			fathers[i] = i;
		}
	}

	int FindSet(int x)
	{
		return fathers[x] == x ? x : fathers[x] = FindSet(fathers[x]);
	}

	void MergeSet(int x, int y)
	{
		fathers[FindSet(x)] = FindSet(y);
	}

	int CountSet(void)
	{
		int n = fathers.size() / 2;
		int ans = 0;
		// set<int> count;
		for (int i = 1; i <= n; ++i)
		{
			// count.insert(FindSet(i));
			ans += fathers[i] == i;
		}
		// return count.size();
		return ans;
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
	DisjointSet ds(n);
	while (m--)
	{
		char op;
		int p, q;
		cin >> op >> p >> q;
		if (op == 'E')
		{
			ds.MergeSet(q + n, p);
			ds.MergeSet(p + n, q);
		}
		else
		{
			ds.MergeSet(p, q);
		}
	}
	cout << ds.CountSet() << endl;
}