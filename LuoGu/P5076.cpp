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
		#define RUN_TIME
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
	RUN_TIME
	return 0;
}

void Solve(void)
{
	set<int> t;
	int q;
	cin >> q;
	while (q--)
	{
		int op, x;
		cin >> op >> x;
		switch (op)
		{
		case 1:
		{
			int ans = 1;
			for (int i : t)
			{
				if (i < x)
					++ans;
				else
					break;
			}
			cout << ans << endl;
		}
		break;
		case 2:
		{
			int cnt = 0;
			int ans;
			for (int i : t)
			{
				++cnt;
				if (cnt == x)
				{
					ans = i;
					break;
				}
			}
			cout << ans << endl;
		}
		break;
		case 3:
		{
			int ans = -2147483647;
			for (int i : t)
			{
				if (i < x)
					ans = i;
				else
					break;
			}
			cout << ans << endl;
		}
		break;
		case 4:
		{
			int ans = 2147483647;
			for (int i : t)
			{
				if (i > x)
				{
					ans = i;
					break;
				}
			}
			cout << ans << endl;
		}
		break;
		case 5:
		{
			t.insert(x);
		}
		break;
		}
	}
}