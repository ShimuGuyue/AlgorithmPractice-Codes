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

bool Check(string s, vector<int64_t>& as, int k, int flag);
int Binary_Search(string s, vector<int64_t> &as, int k);
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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int64_t> as(n);
	cin >> as;

	int ans = Binary_Search(s, as, k);
	cout << ans << endl;
}

int Binary_Search(string s, vector<int64_t> &as, int k)
{
	int l = 0, r = 1e9;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (Check(s, as, k, mid))
			r = mid;
		else
			l = mid + 1;
	}
	return r;
}

bool Check(string s, vector<int64_t> &as, int k, int flag)
{
	// 判断必须选的段被不能选的段分割成的段数
	int n = as.size();
	vector<int> flags;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'B' && as[i] > flag)
			flags.push_back(1);
		if (s[i] == 'R' && as[i] > flag)
			flags.push_back(-1);
	}
	if (flags.empty())
		return true;
	int m = flags.size();
	int count = (flags[0] == 1);
	for (int i = 1; i < m; ++i)
	{
		if (flags[i] == 1 && flags[i - 1] == -1)
			++count;
	}
	return count <= k;
}