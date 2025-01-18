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
	int n, q;
	cin >> n >> q;
	vector<int> nexts(n + 2);
	for (int i = 1; i <= n; ++i)
	{
		nexts[i] = i;
	}
	vector<int> times(n + 1);
	int count = 1;
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r;
			cin >> l >> r;
			for (int i = l; i <= r; ++i)
			{
				if (times[i] == 0)
				{
					times[i] = count++;
					nexts[i] = r;
				}
				else
				{
					i = nexts[i];
				}
			}
		}
		else
		{
			int x;
			cin >> x;
			cout << times[x] << endl;
		}
	}
}