/*-----------------------------------head-----------------------------------*/
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

#pragma region HeadFile

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
#include <iterator>
using std::begin;
using std::end;
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

#pragma endregion 

#pragma region Debug

std::string Debug(const int32_t &i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();
}
std::string Debug(const int64_t &i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();
}

std::string Debug(const double &f)
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(12) << f;
	return ss.str();
}

std::string Debug(const char &c)
{
	std::stringstream ss;
	ss << '\'' << c << '\'';
	return ss.str();
}

std::string Debug(const bool &b)
{
	std::stringstream ss;
	ss << (b ? "true" : "false");
	return ss.str();
}

std::string Debug(const std::string &s)
{
	std::stringstream ss;
	ss << "\"" << s << "\"";
	return ss.str();
}

template <typename T, typename K>
std::string Debug(const std::pair<T, K> &p)
{
	std::stringstream ss;
	ss << "[" << Debug(p.first) << ", " << Debug(p.second) << "]";
	return ss.str();
}

template <typename T>
std::string Debug(const T& t)
{
	std::stringstream ss;
	ss << "{";
	bool first = true;
	for (const auto &a : t)
	{
		if (!first)
			ss << ", ";
		first = false;
		ss << Debug(a);
	}
	ss << "}";
	return ss.str();
}

#pragma endregion

#pragma region IO

template <typename T, typename K>
std::istream& operator>>(std::istream &in, std::pair<T, K> &p)
{
	in >> p.first >> p.second;
	return in;
}
template <typename T, typename K>
std::ostream& operator<<(std::ostream &out, const std::pair<T, K> &p)
{
	out << p.first << ' ' << p.second;
	return out;
}

template <typename T>
std::istream& operator>>(std::istream &in, std::vector<T> &v)
{
	for (T &t : v) in >> t;
	return in;
}
template <typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v)
{
	for (const T &t : v) out << t << ' ';
	return out;
}

#pragma endregion

#pragma region Random

std::mt19937 Rand(time(nullptr));

#pragma endregion

#pragma endregion

/*-----------------------------------body-----------------------------------*/
class HYS
{
public:
	struct Edge
	{
		int u, v, w;

		bool operator<(const Edge &o) const
		{
			return this->w < o.w;
		}
		bool operator>(const Edge &o) const
		{
			return this->w > o.w;
		}
	};
	
	static void Solve(void)
	{// Prim
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int, int>>> grid(n + 1);
		for (int i = 0; i < m; ++i)
		{
			int u, v, w;
			cin >> u >> v >> w;
			grid[u].push_back({v, w});
			grid[v].push_back({u, w});
		}

		vector<bool> used(n + 1, false);
		priority_queue<Edge, vector<Edge>, std::greater<Edge>> h;
		int count = 1;
		int sum = 0;
		used[1] = true;
		for (auto &[v, w] : grid[1])
		{
			h.push({1, v, w});
		}
		while (!h.empty() && count < n)
		{
			auto [u, v, w] = h.top();
			h.pop();

			if (used[v])
				continue;
			used[v] = true;
			++count;
			sum += w;
			for (auto &[vv, ww] : grid[v])
			{
				if (used[vv])
					continue;
				h.push({v, vv, ww});
			}
		}

		if (count == n)
			cout << sum << endl;
		else
			cout << "orz" << endl;
	}

	// static void Solve(void)
	// {//Kruskal
	// 	struct DisjointSet
	// 	{
	// 		vector<int> fathers;

	// 		DisjointSet()
	// 		{}
	// 		DisjointSet(int n) : fathers(n)
	// 		{
	// 			for (int i = 0; i < n; ++i)
	// 			{
	// 				fathers[i] = i;
	// 			}
	// 		}

	// 		int Find(int x)
	// 		{
	// 			return fathers[x] == x ? x : fathers[x] = Find(fathers[x]);
	// 		}

	// 		void Merge(int x, int y)
	// 		{
	// 			fathers[Find(x)] = Find(y);
	// 		}

	// 		bool In_Same_Set(int x, int y)
	// 		{
	// 			return Find(x) == Find(y);
	// 		}
	// 	};
		
	// 	int n, m;
	// 	cin >> n >> m;
	// 	vector<Edge> edges(m);
	// 	for (Edge &e : edges)
	// 	{
	// 		cin >> e.u >> e.v >> e.w;
	// 	}
	// 	sort(edges.begin(), edges.end());

	// 	DisjointSet ds(n + 1);
	// 	int count = 0;
	// 	int sum = 0;
	// 	for (auto &[u, v, w] : edges)
	// 	{
	// 		if (ds.In_Same_Set(u, v))
	// 			continue;
	// 		++count;
	// 		sum += w;
	// 		ds.Merge(u, v);
	// 		if (count == n - 1)
	// 			break;
	// 	}

	// 	if (count == n - 1)
	// 		cout << sum << endl;
	// 	else
	// 		cout << "orz" << endl;
	// }

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
		// HYS::Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}

/** vector<bool> 的使用问题
 * 
 * vector<bool> 直接取值赋值以及将其中元素赋值给 bool 变量没有问题，
 * 但是注意不要把其中元素赋值给 auto，
 * 那样返回的不是 bool 而是一种类似于引用的代理类，
 * 对其进行更改会导致 vector 内的元素一同改变
**/