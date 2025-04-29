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
using std::next_permutation;
#include <random>

std::mt19937 Rand(time(nullptr));

template <typename T, typename K>
std::istream& operator>>(std::istream &in, pair<T, K> &p)
{
	in >> p.first >> p.second;
	return in;
}
template <typename T, typename K>
std::ostream& operator<<(std::ostream &out, pair<T, K> &p)
{
	out << p.first << ' ' << p.second;
	return out;
}
template <typename T>
std::istream& operator>>(std::istream &in, vector<T> &v)
{
	for (T &t : v) in >> t;
	return in;
}
template <typename T>
std::ostream& operator<<(std::ostream &out, vector<T> &v)
{
	for (T &t : v) out << t << ' ';
	return out;
}
#pragma endregion

/*----------------------------------solve-----------------------------------*/

class HYS
{
public:
	static void Solve(void)
	{
		int n, m;
		cin >> n >> m;
		vector<string> grid(n);
		cin >> grid;

		int count1 = 0;
		vector<int> count1s_r(n, 0);
		vector<int> count1s_c(m, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] == '0')
					continue;
				++count1;
				++count1s_r[i];
				++count1s_c[j];
			}
		}

		int count_all1_r = 0;
		int count_all1_c = 0;
		for (int &i : count1s_r)
		{
			if (i == m)
				++count_all1_r;
		}
		for (int &i : count1s_c)
		{
			if (i == n)
				++count_all1_c;
		}
		int count_onlyone0_r = 0;
		int count_onlyone0_c = 0;
		for (int &i : count1s_r)
		{
			if (i == m - 1)
				++count_onlyone0_r;
		}
		for (int &i : count1s_c)
		{
			if (i == n - 1)
				++count_onlyone0_c;
		}

		if (count1 == 0)
			cout << "YES" << endl;
		else if (count1 == m * 2 && count_all1_r == 2)
			cout << "YES" << endl;
		else if (count1 == n * 2 && count_all1_c == 2)
			cout << "YES" << endl;
		else if (count1 == n + m - 2 && count_onlyone0_r == 1 && count_onlyone0_c == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

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
	cin >> t;
	while (t--)
	{ 
		HYS::Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}
