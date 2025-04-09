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
		int n;
		cin >> n;
		vector<int> as(n);
		cin >> as;

		vector<int> flag_indexs;
		int l = 0, r = 0;
		while (l < n && r < n)
		{
			if (as[l])
			{
				flag_indexs.push_back(l);
				r = l + 1;
				while (r < n)
				{
					if (as[r])
					{
						flag_indexs.push_back(r);
						break;
					}
					++r;
				}
				l = r + 1;
			}
			else
			{
				++l;
			}
		}

		int m = flag_indexs.size();
		for (int i = 1; i < m; ++i)
		{
			int dif = abs(as[flag_indexs[i - 1]] - as[flag_indexs[i]]);
			int len = flag_indexs[i] - flag_indexs[i - 1] - 1;
			if (len < dif - 1 || dif % 2 == len % 2)
			{
				cout << -1 << endl;
				return;
			}
		}
		
		if (m == 0)
		{
			for (int i = 1; i <= n; ++i)
			{
				cout << i << " ";
			}
			cout << endl;
			return;
		}

		for (int i = flag_indexs[0] - 1; i >= 0; --i)
		{
			as[i] = as[i + 1] + 1;
		}
		for (int i = flag_indexs[m - 1] + 1; i < n; ++i)
		{
			as[i] = as[i - 1] + 1;
		}
		for (int i = 1; i < m; ++i)
		{
			int ll = flag_indexs[i - 1];
			int rr = flag_indexs[i];
			for (int j = ll + 1; j < rr; ++j)
			{
				if (as[j - 1] > as[rr])
					as[j] = as[j - 1] - 1;
				else
					as[j] = as[j - 1] + 1;
			}
		}
		cout << as << endl;
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
