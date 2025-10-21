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
	vector<pair<int, int>> as(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> as[i].first;
		as[i].second = i;
	}

	sort(as.begin(), as.end(),
	[](pair<int, int> a, pair<int, int> b)
	{
		return a.first < b.first;
	});

	vector<int64_t> sums(n);
	sums[0] = as[0].first;
	for (int i = 1; i < n; ++i)
	{
		sums[i] = sums[i-1] + as[i].first;
	}

	vector<pair<int64_t, int>> anss(n);
	int flag = 0;
	for (int i = 0; i < n; ++i)
	{
		anss[i].second = as[i].second;

		if (flag > i)
			anss[i].first = flag;
		else
		{
			flag = i;
			while (flag < n - 1 && sums[flag] >= as[flag + 1].first)
			{
				++flag;
			}
			anss[i].first = flag;
		}
	}
	sort(anss.begin(), anss.end(),
	[](pair<int64_t, int> a, pair<int64_t, int> b)
	{
		return a.second < b.second;
	});
	for (auto ans : anss)
	{
		cout << ans.first << " ";
	}
	cout << endl;
}