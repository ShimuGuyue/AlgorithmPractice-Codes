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
using std::priority_queue;
using std::set;
using std::map;
using std::sort;
using std::max_element;
using std::min_element;

void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
		freopen(".in.in"  , "r", stdin );
		freopen(".out.out", "w", stdout);
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
	int n, m, k;
	cin >> n >> m >> k;
	priority_queue<int, vector<int>, std::less<int>> odds;
	priority_queue<int, vector<int>, std::less<int>> evens;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if (a & 1)
			odds.push(a);
		else
			evens.push(a);
	}
	while (m || k)
	{
		if (!odds.empty() && !evens.empty())
		{
			if (odds.top() > evens.top())
			{
				if (k)
				{
					int temp = odds.top();
					odds.pop();
					temp ^= 1;
					evens.push(temp);
					--k;
				}
				else
				{
					int temp = evens.top();
					evens.pop();
					temp >>= 1;
					if (temp & 1)
						odds.push(temp);
					else
						evens.push(temp);
					--m;
				}
			}
			else
			{
				if (m)
				{
					int temp = evens.top();
					evens.pop();
					temp >>= 1;
					if (temp & 1)
						odds.push(temp);
					else
						evens.push(temp);
					--m;
				}
				else
				{
					int temp = odds.top();
					odds.pop();
					temp ^= 1;
					evens.push(temp);
					--k;
				}
			}
		}
		else if (!odds.empty() && k)
		{
			int temp = odds.top();
			odds.pop();
			temp ^= 1;
			evens.push(temp);
			--k;
		}
		else if (!evens.empty() && m)
		{
			if (evens.top() == 0)
				break;
			int temp = evens.top();
			evens.pop();
			temp >>= 1;
			if (temp & 1)
				odds.push(temp);
			else
				evens.push(temp);
			--m;
		}
		else
		{
			break;
		}
	}
	int64_t ans = 0;
	while (!odds.empty())
	{
		ans += odds.top();
		odds.pop();
	}
	while (!evens.empty())
	{
		ans += evens.top();
		evens.pop();
	}
	cout << ans << endl;
}