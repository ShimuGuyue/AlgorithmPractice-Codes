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
/*----------------------------------struct----------------------------------*/

/*-----------------------------------head-----------------------------------*/

int64_t Dfs(int index, int last, vector<map<int, int>> &tree, vector<int64_t> &sum_child);
void Solve(void);

/*-----------------------------------main-----------------------------------*/

int main(void)
{
#pragma region
	#ifdef Shimu_Guyue
		freopen("test.in" , "r", stdin );
		freopen("test.out", "w", stdout);
	#else
	#endif

    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	#define endl '\n'
#pragma endregion

    int t = 1;
	// cin >> t;
	// cout << endl;
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
	vector<map<int, int>> tree(n + 1);
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		tree[u][v] = tree[v][u] = abs(u - v);
	}
	
	vector<int64_t> sum_child(n + 1);
	Dfs(1, -1, tree, sum_child);
	int64_t sum = sum_child[1];
	int64_t ans = sum;
	// for(int i=1;i<=n;++i){cout<<i<<":";for(auto[k,v]:tree[i]){cout<<"["<<k<<", "<<v<<"]";}cout << endl;}
	for (map<int, int> m : tree)
	{
		for (auto [e, v] : m)
		{
			ans = std::min(ans, int64_t(llabs(sum_child[e] - (sum - sum_child[e] - v))));
		}
	}
	cout << ans << endl;
}

int64_t Dfs(int index, int last, vector<map<int, int>> &tree, vector<int64_t> &sum_child)
{
	for (auto [e, v] : tree[index])
	{
		if (e == last)
			continue;
		sum_child[index] += v + Dfs(e, index, tree, sum_child);
	}
	tree[index].erase(last);
	return sum_child[index];
}