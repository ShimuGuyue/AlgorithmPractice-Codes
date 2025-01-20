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

int Gcd(int a, int b);
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
	int64_t x, y, a, b, c, d;
	cin >> x >> y >> a >> b >> c >> d;
	int gcdy = Gcd(a, -b);
	int gcdx = Gcd(c, -d);
	if (x % gcdx == 0 && y % gcdy == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int Gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	return Gcd(b, a % b);
}