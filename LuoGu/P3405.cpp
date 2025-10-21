// O2
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
	map<pair<string, string>, int> m;
	for (int i = 0; i < n; ++i)
	{
		string a;
		string b;
		cin >> a >> b;
		a.resize(2);
		++m[pair<string, string>{a, b}];
		m[pair<string, string>{b, a}];	// 提前分配空间，防止后续遍历时迭代器失效
	}
	int64_t ans = 0;
	for (auto pssi : m)
	{
		string a = pssi.first.first;
		string b = pssi.first.second;
		if (a != b)
			ans += m[pair<string, string>{a, b}] * m[pair<string, string>{b, a}];
	}
	ans /= 2;
	cout << ans << endl;
}