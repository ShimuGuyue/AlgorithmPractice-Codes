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

struct Player
{
	int index;
	int value;
};


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
	n = 1 << n;
	queue<Player> q;
	for (int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
		q.push(Player{i, a});
	}
	while (q.size() != 2)
	{
		Player a = q.front();
		q.pop();
		Player b = q.front();
		q.pop();
		q.push(a.value > b.value ? a : b);
	}
	Player a = q.front();
	q.pop();
	Player b = q.front();
	q.pop();
	int ans = a.value > b.value ? b.index : a.index;
	cout << ans << endl;
}

// 另一种做法
// void Solve(void)
// {
// 	int n;
// 	cin >> n;
// 	n = 1 << n;
// 	vector<int> as(n);
// 	for (int i = 0; i < n; ++i)
// 	{
// 		cin >> as[i];
// 	}
// 	int max1 = 0, max2 = 0;
// 	int flag1 = -1, flag2 = -1;
// 	for (int i = 0; i < n / 2; ++i)
// 	{
// 		if (as[i] > max1)
// 			max1 = as[i], flag1 = i + 1;
// 	}
// 	for (int i = n / 2; i < n; ++i)
// 	{
// 		if (as[i] > max2)
// 			max2 = as[i], flag2 = i + 1;
// 	}
// 	int ans = max1 > max2 ? flag2 : flag1;
// 	cout << ans << endl;
// }