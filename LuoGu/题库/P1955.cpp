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
	map<int, int> fathers;

	int FindSet(int x)
	{
		if (fathers[x] == 0)
			fathers[x] = x;
		return fathers[x] == x ? x : fathers[x] = FindSet(fathers[x]);
	}

	void MergeSet(int x, int y)
	{
		fathers[FindSet(x)] = FindSet(y);
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
	cin >> t;
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
	// O2
	struct Order
	{
		int i, j, e;
	};

	int n;
	cin >> n;
	DisjointSet ds;
	vector<Order> orders(n);
	for (int k = 0; k < n; ++k)
	{
		cin >> orders[k].i >> orders[k].j >> orders[k].e;
	}
	sort(orders.begin(), orders.end(),
	[](Order a, Order b)
	{
		return a.e > b.e;
	});

	bool ok = true;
	for (int k = 0; k < n; ++k)
	{
		int i = orders[k].i;
		int j = orders[k].j;
		int e = orders[k].e;
		if (e == 1)
		{
			ds.MergeSet(i, j);
		}
		else
		{
			if (ds.FindSet(i) == ds.FindSet(j))
				ok = false;
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
}