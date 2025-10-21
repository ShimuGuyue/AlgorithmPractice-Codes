/*-----------------------------------head-----------------------------------*/
#pragma region template

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
#include <sstream>
using std::stringstream;
#include <fstream>
using std::ifstream;
using std::ofstream;
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
using std::prev_permutation;
using std::find;
using std::find_if;
using std::count;
using std::count_if;
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
template <typename T>
std::ostream& operator>>(std::ostream &out, const std::vector<T> &v)
{
	for (auto rit = v.rbegin(); rit != v.rend(); ++rit)
		out << *rit << ' ';
	return out;
}

#pragma endregion

#pragma region Struct

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

struct DisjointSet
{
	vector<int> sets;
	vector<int> ranks;

	DisjointSet()
	{}
	DisjointSet(const int &n) : sets(n), ranks(n, 1)
	{
		for (int i = 0; i < n; ++i)
		{
			sets[i] = i;
		}
	}

	int Find_Set(const int &x)
	{
		return sets[x] == x ? x : sets[x] = Find_Set(sets[x]);
	}

	void Merge_Set(const int &x, const int &y)
	{
		int set_x = Find_Set(x);
		int set_y = Find_Set(y);
		if (ranks[set_x] < ranks[set_y])
		{
			sets[set_x] = set_y;
		}
		else
		{
			sets[set_y] = set_x;
			if (ranks[set_x] == ranks[set_y])
				++ranks[set_x];
		}
	}

	bool In_Same_Set(const int &x, const int &y)
	{
		return Find_Set(x) == Find_Set(y);
	}
};

#pragma endregion

#pragma region Random

std::mt19937 Rand(time(nullptr));

#pragma endregion

#pragma region Nickname

template <typename T>
using MaxHeap = std::priority_queue<T, std::vector<T>, std::less<T>>;
template <typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#pragma endregion

#pragma endregion

/*-----------------------------------body-----------------------------------*/
class HYS
{
public:
	static void Solve(void)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> grid[i][j];
			}
		}

		vector<pair<string, int>> ans;
		if (n < m)
		{
			for (int i = 1; i <= n; ++i)
			{
				int min = 1e9;
				for (int j = 1; j <= m; ++j)
				{
					min = std::min(min, grid[i][j]);
				}
				for (int j = 1; j <= m; ++j)
				{
					grid[i][j] -= min;
				}
				while (min--)
				{
					ans.push_back({"row", i});
				}
			}
			for (int j = 1; j <= m; ++j)
			{
				int min = 1e9;
				for (int i = 1; i <= n; ++i)
				{
					min = std::min(min, grid[i][j]);
				}
				for (int i = 1; i <= n; ++i)
				{
					grid[i][j] -= min;
				}
				while (min--)
				{
					ans.push_back({"col", j});
				}
			}
		}
		else
		{
			for (int j = 1; j <= m; ++j)
			{
				int min = 1e9;
				for (int i = 1; i <= n; ++i)
				{
					min = std::min(min, grid[i][j]);
				}
				for (int i = 1; i <= n; ++i)
				{
					grid[i][j] -= min;
				}
				while (min--)
				{
					ans.push_back({"col", j});
				}
			}
			for (int i = 1; i <= n; ++i)
			{
				int min = 1e9;
				for (int j = 1; j <= m; ++j)
				{
					min = std::min(min, grid[i][j]);
				}
				for (int j = 1; j <= m; ++j)
				{
					grid[i][j] -= min;
				}
				while (min--)
				{
					ans.push_back({"row", i});
				}
			}
		}

		int count0 = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				count0 += (grid[i][j] == 0);
			}
		}
		if (count0 != n * m)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << ans.size() << endl;
			for (auto &a : ans)
			{
				cout << a << endl;
			}
		}
	}

	// static 
};

/*-----------------------------------main-----------------------------------*/
int main(void)
{
	#ifdef Shimu_Guyue
		freopen(".test/in.test" , "r", stdin );
		freopen(".test/out.test", "w", stdout);
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

/** vector<bool> 的使用问题
 *
 * vector<bool> 直接取值赋值以及将其中元素赋值给 bool 变量没有问题，
 * 但是注意不要把其中元素赋值给 auto，
 * 那样返回的不是 bool 而是一种类似于引用的代理类，
 * 对其进行更改会导致 vector 内的元素一同改变
**/