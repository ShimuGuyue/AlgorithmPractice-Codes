//  $$$$$$\  $$\   $$\     $$\  $$$$$$\  $$$$$$\  $$$$$$\  
// $$  __$$\ $$ |  \$$\   $$  |$$  __$$\ \_$$  _|$$  __$$\ 
// $$ /  $$ |$$ |   \$$\ $$  / $$ /  \__|  $$ |  $$ /  $$ |
// $$$$$$$$ |$$ |    \$$$$  /  \$$$$$$\    $$ |  $$$$$$$$ |
// $$  __$$ |$$ |     \$$  /    \____$$\   $$ |  $$  __$$ |
// $$ |  $$ |$$ |      $$ |    $$\   $$ |  $$ |  $$ |  $$ |
// $$ |  $$ |$$$$$$$$\ $$ |    \$$$$$$  |$$$$$$\ $$ |  $$ |
// \__|  \__|\________|\__|     \______/ \______|\__|  \__|
// 你是否赞同纯美女神爱莉希雅的美貌盖世无双？【愛門】!
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <climits>
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
using std::to_string;
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

void Solve(void)
{
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> as(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> as[i];
	}

	priority_queue<int, vector<int>, std::greater<int>> lm;
	priority_queue<int, vector<int>, std::greater<int>> rm;
	for (int i = 1; i <= r; ++i)
	{
		lm.push(as[i]);
	}
	for (int i = l; i <= n; ++i)
	{
		rm.push(as[i]);
	}

	int64_t ans1 = 0;
	for (int i = 0; i < r - l + 1; ++i)
	{
		ans1 += lm.top();
		lm.pop();
	}
	int64_t ans2 = 0;
	for (int i = 0; i < r - l + 1; ++i)
	{
		ans2 += rm.top();
		rm.pop();
	}

	int64_t ans = std::min(ans1, ans2);
	cout << ans << endl;
}