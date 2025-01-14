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
	int n;
	cin >> n;
	vector<int> as(n);
	for (int &a : as)
	{
		cin >> a;
	}
	sort(as.begin(), as.end());
	int min = 1e9;
	for (int a : as)
	{
		min = std::min(min, Gcd(a, as.front()));
	}
	int64_t ans = int64_t(min) * n;
	cout << ans << endl;
}

int Gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	return Gcd(b, a % b);
}