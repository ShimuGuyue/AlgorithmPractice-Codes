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
	cin >> t;
	while (t--)
	{
		Solve();
		// cout << endl;
	}
	return 0;
}

void Solve(void)
{
	int a, b, d, e;
	cin >> a >> b >> d >> e;
	int ans = 0;
	int c;
	int count;

	count = 0;
	c = a + b;
	if (a + b == c)
		++count;
	if (b + c == d)
		++count;
	if (c + d == e)
		++count;
	ans = std::max(ans, count);

	count = 0;
	c = d - b;
	if (a + b == c)
		++count;
	if (b + c == d)
		++count;
	if (c + d == e)
		++count;
	ans = std::max(ans, count);

	count = 0;
	c = e - d;
	if (a + b == c)
		++count;
	if (b + c == d)
		++count;
	if (c + d == e)
		++count;
	ans = std::max(ans, count);

	cout << ans << endl;
}