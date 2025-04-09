#pragma region
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
		int n, k;
		cin >> n >> k;
		vector<int> as(n + 1);
		vector<int> bs(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> as[i];
		}
		for (int i = 1; i <= n; ++i)
		{
			cin >> bs[i];
		}

		vector<int64_t> dp_a(n + 1, -1);
		vector<int64_t> dp_b(n + 1, -1);
		dp_a[1] = as[1];
		dp_a[2] = dp_a[1] + as[2];
		dp_b[2] = dp_a[1] >= k ? dp_a[1] - k + bs[2] : -1;
		for (int i = 3; i <= n; ++i)
		{
			dp_a[i] = dp_a[i - 1] + as[i];
			if (dp_b[i - 1] >= k)
				dp_a[i] = std::max(dp_a[i], dp_b[i - 1] - k + as[i]);

			if (dp_b[i - 1] != -1)
				dp_b[i] = dp_b[i - 1] + bs[i];
			if (dp_a[i - 1] >= k)
				dp_b[i] = std::max(dp_b[i], dp_a[i - 1] - k + bs[i]);
		}
		int64_t ans = std::max(dp_a[n], dp_b[n]);
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
	#ifdef Shimu_Guyue
		freopen( "in.test", "r", stdin );
		freopen("out.test", "w", stdout);
	#endif
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
	// cin >> t;
	while (t--)
	{ 
		HYS::Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}
