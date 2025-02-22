//  $$$$$$\  $$\   $$\     $$\  $$$$$$\  $$$$$$\  $$$$$$\  
// $$  __$$\ $$ |  \$$\   $$  |$$  __$$\ \_$$  _|$$  __$$\ 
// $$ /  $$ |$$ |   \$$\ $$  / $$ /  \__|  $$ |  $$ /  $$ |
// $$$$$$$$ |$$ |    \$$$$  /  \$$$$$$\    $$ |  $$$$$$$$ |
// $$  __$$ |$$ |     \$$  /    \____$$\   $$ |  $$  __$$ |
// $$ |  $$ |$$ |      $$ |    $$\   $$ |  $$ |  $$ |  $$ |
// $$ |  $$ |$$$$$$$$\ $$ |    \$$$$$$  |$$$$$$\ $$ |  $$ |
// \__|  \__|\________|\__|     \______/ \______|\__|  \__|
// 您是否赞同纯美女神爱莉希雅的美貌盖世无双？【愛門】!
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
using std::pair;
using std::string;
using std::to_string;
using std::vector;
using std::deque;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::bitset;
using std::lower_bound;
using std::upper_bound;
using std::sort;
using std::max_element;
using std::min_element;

/*----------------------------------struct----------------------------------*/

/*-----------------------------------head-----------------------------------*/

void Solve(void);

/*-----------------------------------main-----------------------------------*/

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
		// cout << "-------------------------" << endl;
	}
	return 0;
}

/*-----------------------------------body-----------------------------------*/

void Solve(void)
{
	int n;
	cin >> n;
	vector<int> as(n);
	for (auto &a : as)
	{
		cin >> a;
	}

	if (n == 1)
	{
		cout << 0 << endl;
		return;
	}

	int ans = 1e6;
	vector<int> increace_lens(n);	// 成环连续上升长度
	vector<int> decreace_lens(n);	// 成环连续下降长度
	for (int i = 0; i < 2 * n; ++i)
	{
		increace_lens[i % n] = 1;
		if (as[i % n] >= as[(i+n-1) % n])
			increace_lens[i % n] += increace_lens[(i+n-1) % n];
		decreace_lens[i % n] = 1;
		if (as[i % n] <= as[(i+n-1) % n])
			decreace_lens[i % n] += decreace_lens[(i+n-1) % n];

		if (decreace_lens[i % n] == n)
		{
			if (i % n == n - 1)
				ans = 1;
			ans = std::min(ans, std::min(n - (i % n), 1 + (i % n) + 1));
		}
		// 上升的判断放在下降之后，防范整个序列都是相同元素不需要移动的情况
		if (increace_lens[i % n] == n)
		{
			if (i % n == n - 1)
				ans = 0;
			ans = std::min(ans, std::min(n - (i % n) - 1, 2 + (i % n) + 1));
		}
	}
	cout << (ans == int(1e6) ? -1 : ans) << endl;
}