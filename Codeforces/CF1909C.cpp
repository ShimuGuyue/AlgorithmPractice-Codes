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
	vector<int> ls(n);
	map<int, int> rs;
	for (int i = 0; i < n; ++i)
	{
		cin >> ls[i];
	}
	for (int i = 0; i < n; ++i)
	{
		int r;
		cin >> r;
		++rs[r];
	}
	
	sort(ls.rbegin(), ls.rend());
	vector<int> lens(n);
	for (int i = 0; i < n; ++i)
	{
		int l = ls[i];
		int r = rs.upper_bound(l)->first;
		lens[i] = r - l;
		--rs[r];
		if (rs[r] == 0)
			rs.erase(r);
	}
	sort(lens.begin(), lens.end());
	
	vector<int> cs(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> cs[i];
	}
	sort(cs.rbegin(), cs.rend());

	int64_t ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += int64_t(cs[i]) * lens[i];
	}
	cout << ans << endl;
}