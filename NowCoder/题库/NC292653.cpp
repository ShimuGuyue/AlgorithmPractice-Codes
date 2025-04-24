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
		int n;
		cin >> n;
		vector<int> values(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> values[i];
		}

		vector<int> degrees(n + 1);
		for (int i = 1; i < n; ++i)
		{
			int u, v;
			cin >> u >> v;
			++degrees[u];
			++degrees[v];
		}

		vector<int> leaves;
		for (int i = 1; i <= n; ++i)
		{
			// 如果树上只有一个节点，该节点的度数为 0
			if (degrees[i] <= 1)
				leaves.push_back(values[i]);
		}

		int64_t ans = 0;
		sort(leaves.rbegin(), leaves.rend());
		int m = leaves.size();
		for (int i = 0; i < m; ++i)
		{
			ans += leaves[i];
		}
		if (m & 1)
			ans += *min_element(values.begin() + 1, values.end());
		cout << ans << endl;
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
	// cin >> t;
	while (t--)
	{ 
		HYS::Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}
