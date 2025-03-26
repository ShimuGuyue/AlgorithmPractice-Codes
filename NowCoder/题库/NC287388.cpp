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
		vector<int> as(n);
		int sum = 0;
		for (int &a : as)
		{
			cin >> a;
			sum += a;
		}
		sort(as.begin(), as.end());
		if (sum - as.back() <= as.back())
		{
			cout << -1 << endl;
			return;
		}

		int ans = 1e9;
		set<int> digits;
		for (int i = 1; i < n - 1; ++i)
		{
			vector<int> digits_v(digits.begin(), digits.end());
			for (int j = 0; j < i; ++j)
			{
				int temp = as[j] + as[i];
				if (temp > as[i + 1])
					ans = std::min(ans, temp + as[i + 1]);
				digits.insert(temp);
			}
			for (auto &d : digits_v)
			{
				int temp = d + as[i];
				if (temp > as[i + 1])
					ans = std::min(ans, temp + as[i + 1]);
				digits.insert(temp);
			}
		}
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
