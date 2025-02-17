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
	deque<int64_t> as(n);
	for (auto &a : as)
	{
		cin >> a;
	}

	vector<int64_t> sums_front_positive(n);
	vector<int64_t> sums_back_negative(n);
	sums_front_positive[0] = as[0] >= 0 ? abs(as[0]) : 0;
	for (int i = 1; i < n; ++i)
	{
		if (as[i] >= 0)
			sums_front_positive[i] = sums_front_positive[i-1] + abs(as[i]);
		else
			sums_front_positive[i] = sums_front_positive[i-1];
	}
	sums_back_negative[n-1] = as[n-1] < 0 ? abs(as[n-1]) : 0;
	for (int i = n - 2; i >= 0; --i)
	{
		if (as[i] < 0)
			sums_back_negative[i] = sums_back_negative[i+1] + abs(as[i]);
		else
			sums_back_negative[i] = sums_back_negative[i+1];
	}

	int64_t ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = std::max(ans, sums_front_positive[i] + sums_back_negative[i]);
	}
	cout << ans << endl;
}