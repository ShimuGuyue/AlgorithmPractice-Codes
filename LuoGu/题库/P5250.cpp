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
	set<int> t;
	while (n--)
	{
		int op, length;
		cin >> op >> length;
		if (op == 1)
		{
			if (t.find(length) == t.end())
				t.insert(length);
			else
				cout << "Already Exist" << endl;
		}
		else
		{
			if (t.empty())
			{
				cout << "Empty" << endl;
				continue;
			}

			auto it = t.lower_bound(length);
			if (it != t.end() && *it == length) // 有
			{
				cout << *it << endl;
				t.erase(it);
			}
			else
			{
				auto jt = it; --jt;
				if (it == t.begin())
				{
					cout << *it << endl;
					t.erase(it);
				}
				else if (it == t.end())
				{
					cout << *jt << endl;
					t.erase(jt);
				}
				else if (*it - length < length - *jt)
				{
					cout << *it << endl;
					t.erase(it);
				}
				else
				{
					cout << *jt << endl;
					t.erase(jt);
				}
			}
		}
	}
}