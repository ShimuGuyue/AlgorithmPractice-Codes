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

void Solve(void);

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
		// cout << endl;
	}
	return 0;
}

void Solve(void)
{
	int n;
	cin >> n;
	map<int, int> counts;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		++counts[a];
	}
	int max = 0, min = n;
	for (auto ii : counts)
	{
		if (ii.second == 0)
		{
			cout << "NO" << endl;
			return;
		}
		max = std::max(max, ii.second);
		min = std::min(min, ii.second);
	}
	if (max - min <= 1)
		cout << "YES" << std::endl;
	else
		cout << "NO" << endl;
}