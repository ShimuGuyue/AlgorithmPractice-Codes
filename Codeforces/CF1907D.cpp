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

struct Loc
{
	int l;
	int r;
};

/*-----------------------------------head-----------------------------------*/

bool Check(vector<Loc> &locs, int n, int k);
int Binary_Search(vector<Loc> &locs, int n);
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
	vector<Loc> locs(n);
	for (auto &loc : locs)
	{
		cin >> loc.l >> loc.r;
	}
	int ans = Binary_Search(locs, n);
	cout << ans << endl;
}

int Binary_Search(vector<Loc> &locs, int n)
{
	int l = 0, r = 1e9;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (Check(locs, n, mid))
			r = mid;
		else
			l = mid + 1;
	}
	return r;
}

bool Check(vector<Loc> &locs, int n, int k)
{
	int l = 0, r = 0;
	for (int i = 0; i < n; ++i)
	{
		if (r + k < locs[i].l || l - k > locs[i].r)
			return false;
		l = std::max(l - k, locs[i].l);
		r = std::min(r + k, locs[i].r);
	}
	return true;
}