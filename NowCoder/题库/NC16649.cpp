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
	// cin >> t;
	while (t--)
	{
		Solve();
		// cout << endl << "-------------------------" << endl;
	}
	return 0;
}

/* 离散化 */
void Solve(void)
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> ranges(m);
	for (auto &ii : ranges)
	{
		cin >> ii.first >> ii.second;
	}
	sort(ranges.begin(), ranges.end(),
	[](pair<int, int> a, pair<int, int> b)
	{
		return a.first < b.first;
	});

	int ans = n + 1;
	int l = ranges[0].first;
	int r = ranges[0].second;
	for (int i = 1; i < m; ++i)
	{
		if (ranges[i].first <= r)
		{
			r = std::max(r, ranges[i].second);
		}
		else
		{
			ans -= r - l + 1;
			l = ranges[i].first;
			r = ranges[i].second;
		}
	}
	ans -= r - l + 1;
	cout << ans << endl;
}

/* 差分 */
// void Solve(void)
// {
// 	int l, m;
// 	cin >> l >> m;
// 	vector<int> difs(l + 1);
// 	difs.front() = 1;
// 	while (m--)
// 	{
// 		int a, b;
// 		cin >> a >> b;
// 		--difs[a];
// 		if (b + 1 <= l)
// 			++difs[b + 1];
// 	}
// 	int ans = 0;
// 	vector<int> trees(l + 1);
// 	for (int i = 0; i <= l; ++i)
// 	{
// 		if (i == 0)
// 			trees[i] = difs[i];
// 		else
// 			trees[i] = trees[i - 1] + difs[i];
// 		if (trees[i] == 1)
// 			++ans;
// 	}
// 	cout << ans << endl;
// }