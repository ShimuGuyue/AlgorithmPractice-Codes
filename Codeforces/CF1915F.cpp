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
#include <list>
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
using std::stoi;
using std::vector;
using std::deque;
using std::list;
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

template <typename T>
std::istream& operator>>(std::istream &in, vector<T> &v)
{
	for (T &t : v) in >> t;
	return in;
}
template <typename T>
std::ostream& operator<<(std::ostream &out, vector<T> &v)
{
	for (T &t : v) out << t << " ";
	return out;
}

/*----------------------------------struct----------------------------------*/

/*-----------------------------------head-----------------------------------*/

vector<int> temp;

void Merge_Sort(vector<int> &as, int l, int r, int64_t& count);
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
	vector<pair<int, int>> locs(n);
	for (auto &ii : locs)
	{
		cin >> ii.first >> ii.second;
	}
	sort(locs.begin(), locs.end());
	// for (auto ii : locs)cout<<ii.first<<" " << ii.second << endl;
	// 求逆序对个数
	vector<int> as(n);
    temp = vector<int>(as.size());
	for (int i = 0; i < n; ++i)
	{
		as[i] = locs[i].second;
	}
	int64_t ans = 0;
	Merge_Sort(as, 0, n - 1, ans);
	cout << ans << endl;
}

void Merge_Sort(vector<int> &as, int l, int r, int64_t& count)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    Merge_Sort(as, l, mid, count);
    Merge_Sort(as, mid + 1, r, count);

    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k)
    {
        if ((j > r) || (i <= mid && as[i] < as[j]))
            temp[k] = as[i++];
        else
            temp[k] = as[j++], count += mid - i + 1;
    }
    for (int i = l; i <= r; ++i)
    {
        as[i] = temp[i];
    }
}