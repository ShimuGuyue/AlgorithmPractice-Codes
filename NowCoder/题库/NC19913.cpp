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

void Solve(void)
{
	int n, b;
	cin >> n >> b;
	vector<int> cmps(n);
	int flag;
	for (int i = 0; i < n; ++i)
	{
		cin >> cmps[i];
		if (cmps[i] == b)
		{
			flag = i;
			cmps[i] = 0;
		}
		else
		if (cmps[i] > b)
		{
			cmps[i] = 1;
		}
		else
		if (cmps[i] < b)
		{
			cmps[i] = -1;
		}
	}

	int ans = 1;

	map<int, int> counts_r;
	++counts_r[0];
	vector<int> sums_r(n);
	for (int i = flag + 1; i < n; ++i)
	{
		sums_r[i] = sums_r[i - 1] + cmps[i];
		++counts_r[sums_r[i]];
		if (sums_r[i] == 0)
			++ans;
	}
	vector<int> sums_l(n);
	for (int i = flag - 1; i >= 0; --i)
	{
		sums_l[i] = sums_l[i + 1] + cmps[i];
		ans += counts_r[-sums_l[i]];
	}
	cout << ans << endl;
}