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
	string s;
	cin >> s;
	int n = s.size() / 2;
	string s1 = string(s.begin(), s.begin() + n);
	string s2 = string(s.begin() + n, s.end());
	map<char, int> m1;
	map<char, int> m2;
	for (char c : s1)
	{
		++m1[c];
	}
	for (char c : s2)
	{
		++m2[c];
	}
	int max1 = 0, max2 = 0;
	for (pair<char, int> ci : m1)
	{
		max1 = std::max(max1, ci.second);
	}
	for (pair<char, int> ci : m2)
	{
		max2 = std::max(max2, ci.second);
	}
	int ans = n * 2 - max1 - max2;
	cout << ans << endl;
}