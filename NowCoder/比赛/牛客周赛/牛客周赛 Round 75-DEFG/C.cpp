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
	const int64_t mod = 1e9+7;

	int64_t n;
	cin >> n;
	int64_t a = n / 2;
	int64_t b = n - a;
	int64_t ans = 1;
	for (int i = 1; i <= a; ++i)
	{
		ans *= i; ans %= mod;
	}
	for (int i = 1; i <= b; ++i)
	{
		ans *= i; ans %= mod;
	}
	if (n % 2 == 0)
	{
		ans *= 2; ans %= mod;
	}
	cout << ans << endl;
}