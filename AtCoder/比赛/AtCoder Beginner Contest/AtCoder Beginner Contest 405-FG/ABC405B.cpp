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

struct SegementTree
{
	struct Node
	{
		int l, r;
		int64_t sum = 0;
		int64_t lazy_sum = 0;

		bool In_Range(int left, int right)
		{
			return l >= left && r <= right;
		}

		bool Out_Range(int left, int right)
		{
			return l > right || r < left;
		}

		int Length(void)
		{
			return r - l + 1;
		}
	};

	vector<Node> tree;

	SegementTree()
	{}
	SegementTree(const vector<int64_t> &data) : tree(data.size() * 4)
	{
		Build(data, 0, 1, data.size() - 1);
	}

	void Make_Tag(int node, int64_t value)
	{
		tree[node].lazy_sum += value;
		tree[node].sum += value * tree[node].Length();
	}

	void Pushup(int node)
	{
		int node_l = node * 2 + 1;
		int node_r = node * 2 + 2;
		tree[node].sum = tree[node_l].sum + tree[node_r].sum;
	}

	void Pushdown(int node)
	{
		int node_l = node * 2 + 1;
		int node_r = node * 2 + 2;
		Make_Tag(node_l, tree[node].lazy_sum);
		Make_Tag(node_r, tree[node].lazy_sum);
		tree[node].lazy_sum = 0;
	}

	void Build(const vector<int64_t> &data, int node, int l, int r)
	{
		tree[node].l = l;
		tree[node].r = r;
		if (l == r)
		{
			tree[node].sum = data[l];
			return;
		}

		int mid = (l + r) / 2;
		int node_l = node * 2 + 1;
		int node_r = node * 2 + 2;
		Build(data, node_l, l, mid);
		Build(data, node_r, mid + 1, r);
		Pushup(node);
	}

	void Update(int l, int r, int64_t value, int node = 0)
	{
		if (tree[node].Out_Range(l, r))
			return;
		if (tree[node].In_Range(l, r))
		{
			Make_Tag(node, value);
			return;
		}
		Pushdown(node);
		int node_l = node * 2 + 1;
		int node_r = node * 2 + 2;
		Update(l, r, value, node_l);
		Update(l, r, value, node_r);
		Pushup(node);
	}

	int64_t Query(int l ,int r, int node = 0)
	{
		if (tree[node].Out_Range(l, r))
			return 0;
		if (tree[node].In_Range(l, r))
			return tree[node].sum;
		Pushdown(node);
		int node_l = node * 2 + 1;
		int node_r = node * 2 + 2;
		return Query(l, r, node_l)
			+  Query(l, r, node_r);
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
		vector<int> as(n);
		cin >> as;
		vector<int> counts(m + 1, 0);
		for (int a : as)
		{
			if (a <= m)
				++counts[a];
		}

		bool fail = (find(counts.begin() + 1, counts.end(), 0) != counts.end());
		if (fail)
		{
			cout << 0 << endl;
			return;
		}

		int ans = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			++ans;
			if (as[i] > m)
				continue;
			--counts[as[i]];
			if (counts[as[i]] == 0)
			{
				cout << ans << endl;
				return;
			}
		}
	}

	// static 

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