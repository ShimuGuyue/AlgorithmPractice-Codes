/*
/$$$$$$\  $$\   $$\     $$\  $$$$$$\  $$$$$$\  $$$$$$\  
$$  __$$\ $$ |  \$$\   $$  |$$  __$$\ \_$$  _|$$  __$$\ 
$$ /  $$ |$$ |   \$$\ $$  / $$ /  \__|  $$ |  $$ /  $$ |
$$$$$$$$ |$$ |    \$$$$  /  \$$$$$$\    $$ |  $$$$$$$$ |
$$  __$$ |$$ |     \$$  /    \____$$\   $$ |  $$  __$$ |
$$ |  $$ |$$ |      $$ |    $$\    $$|  $$ |  $$ |  $$ |
$$ |  $$ |$$$$$$$$\ $$ |    \$$$$$$  |$$$$$$\ $$ |  $$ |
\__|  \__|\________|\__|     \______/ \______|\__|  \__|
您是否赞同纯美女神爱莉希雅的美貌盖世无双？【愛門】!
*/

#pragma region

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::fixed;
using std::setprecision;
using std::setw;
#include <cstdint>
#include <climits>
#include <cmath>
#include <utility>
using std::pair;
#include <string>
using std::string;
using std::to_string;
using std::stoi;
#include <vector>
using std::vector;
#include <deque>
using std::deque;
#include <list>
using std::list;
#include <stack>
using std::stack;
#include <queue>
using std::queue;
using std::priority_queue;
#include <set>
using std::set;
#include <map>
using std::map;
#include <bitset>
using std::bitset;
#include <algorithm>
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
#pragma endregion

/*----------------------------------solve-----------------------------------*/

class HYS
{
public:
	static void Solve(void)
	{
		int n;
		cin >> n;
		vector<int64_t> as(n);
		cin >> as;
		vector<int64_t> dp(n);
		dp[0] = as[0];
		dp[1] = std::max(dp[0] + as[1], int64_t(0));
		dp[2] = std::max({dp[1] + as[2], dp[0], int64_t(0)});
		for (int i = 3; i < n; ++i)
		{
			dp[i] = dp[i - 1] + as[i];
			dp[i] = std::max({dp[i], dp[i - 2], dp[i - 3]});
		}
		int64_t ans = dp.back();
		cout << ans << endl;
	}

	// static 
	// static 
	// static 
	// static 
	// static 
};

/*-----------------------------------main-----------------------------------*/

int main(void)
{
#pragma region
	#ifdef Shimu_Guyue
		freopen("in.test" , "r", stdin );
		freopen("out.test", "w", stdout);
	#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#pragma endregion

    int t = 1;
	cin >> t;
	// cout << endl;
	while (t--)
	{ 
		HYS::Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}
