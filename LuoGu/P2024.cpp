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
using std::to_string;
using std::vector;
using std::deque;
using std::queue;
using std::stack;
using std::priority_queue;
// using std::set;
using std::map;
using std::sort;
using std::max_element;
using std::min_element;

/*----------------------------------struct----------------------------------*/

struct DisjointSet
{
	vector<int> fathers;

	DisjointSet(int n) : fathers(n * 3 + 1)
	{
		for (int i = 0; i <= n * 3; ++i)
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
		freopen("../../test.in" , "r", stdin );
		freopen("../../test.out", "w", stdout);
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
	int n, k;
	cin >> n >> k;
	DisjointSet ds(n);
	int ans = 0;
	while (k--)
	{
		int op, x, y;
		cin >> op >> x >> y;

		if (x > n || y > n)
		{
			++ans;
			continue;
		}

		if (op == 1)
		{
			if (ds.Find(x) == ds.Find(y + n) || ds.Find(x) == ds.Find(y + n * 2))
			{
				++ans;
				continue;
			}

			ds.Merge(x, y);
			ds.Merge(x + n, y + n);
			ds.Merge(x + n * 2, y + n * 2);
		}
		else
		{
			if (x == y)
			{
				++ans;
				continue;
			}

			if (ds.Find(x) == ds.Find(y) || ds.Find(x) == ds.Find(y + n))
			{
				++ans;
				continue;
			}

			ds.Merge(x, y + n * 2);
			ds.Merge(x + n, y);
			ds.Merge(x + n * 2, y + n);
		}
	}
	cout << ans << endl;
}