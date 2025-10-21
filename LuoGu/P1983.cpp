/*-----------------------------------head-----------------------------------*/
#pragma region template
// https://github.com/ShimuGuyue/AlgorithmPractice-Codes

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
using std::setw;
using std::fixed;
using std::setprecision;
#include <utility>
using std::pair;
using std::swap;
#include <string>
using std::string;
using std::to_string;
using std::stoi;
using std::stoll;
using std::stod;
#include <array>
using std::array;
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
using std::multiset;
#include <unordered_set>
using std::unordered_set;
using std::unordered_multiset;
#include <map>
using std::map;
using std::multimap;
#include <unordered_map>
using std::unordered_map;
using std::unordered_multimap;
#include <iterator>
using std::prev;
using std::next;
#include <bitset>
using std::bitset;
#include <algorithm>
using std::sort;
using std::stable_sort;
using std::max_element;
using std::min_element;
using std::lower_bound;
using std::upper_bound;
using std::prev_permutation;
using std::next_permutation;
#include <numeric>
using std::gcd;
using std::lcm;
using std::iota;
#include <cstdint>
#include <climits>
#include <cmath>
#include <random>

#pragma endregion

#pragma region Debug

#ifdef Shimu_Guyue
	#include "Debug.h"
	template <typename T>
	void debug(const T &t, int mod = 0)
	{
		Debug(t, mod);
	}
#else
	#define Debug(...)
#endif

#pragma endregion

#pragma region IO

// std::pair
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

// std::array
template <typename T, size_t N>
std::istream& operator>>(std::istream &in, std::array<T, N> &a)
{
	for (T &t : a) in >> t;
	return in;
}
template <typename T, size_t N>
std::ostream& operator<<(std::ostream &out, const std::array<T, N> &a)
{
	for (const T &t : a) out << t << ' ';
	return out;
}

// std::vector
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

	friend std::istream &operator>>(std::istream &in, Edge &e)
	{
		in >> e.u >> e.v >> e.w;
		return in;
	}
};

class DisjointSet
{
private:
	struct Node
	{
		int parent;	// 父节点
		int rank;	// 秩
	};

	vector<Node> nodes;	// 存储每个节点的信息

public:
	DisjointSet(const int n) : nodes(n)
	{
		for (int i = 0; i < n; ++i)
		{
			nodes[i] = {i, 1};
		}
	}

	int Find(int x)
	{
		return (nodes[x].parent == x) ? x : (nodes[x].parent = Find(nodes[x].parent));
	}

	void Merge(const int x, const int y)
	{
		int setX = Find(x);
		int setY = Find(y);
		if (nodes[setX].rank < nodes[setY].rank)
		{
			nodes[setX].parent = setY;
		}
		else
		{
			nodes[setY].parent = setX;
			if (nodes[setX].rank == nodes[setY].rank)
				++nodes[setX].rank;
		}
	}
};

#pragma endregion

#pragma region Function

int64_t Pow(int base, int n)
{
	int64_t ans = 1;
	while (n)
	{
		if (n & 1)
			ans *= base;
		base *= base;
		n >>= 1;
	}
	return ans;
}

int64_t Pow(int base, int n, int mod)
{
	int64_t ans = 1;
	while (n)
	{
		if (n & 1)
			ans = ans * base % mod;
		base = base * base % mod;
		n >>= 1;
	}
	return ans;
}

int64_t Ceil(int64_t a, int64_t b)
{
	return a / b + (a % b != 0);
}

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

class ShimuGuyue
{
// test case
public:
	static const bool MULTIPLE_TESTS = false;
// struct
public:
	struct 
	{};
// function
public:
	static void Solve()
	{
		int n, m;
		cin >> n >> m;

		vector<vector<int>> grid(n + 1, vector<int>(n + 1));
		while (m--)
		{
			int s;
			cin >> s;
			vector<int> have(n + 1);
			vector<int> as(s);
			for (int &a : as)
			{
				cin >> a;
				have[a] = 1;
			}

			for (int i = as.front() + 1; i < as.back(); ++i)
			{
				if (have[i])
					continue;
				for (int a : as)
				{
					grid[a][i] = 1;
				}
			}
		}

		vector<int> counts_front(n + 1);
		for (int j = 1; j <= n; ++j)
		{
			for (int i = 0; i <= n; ++i)
			{
				counts_front[j] += grid[i][j];
			}
		}

		vector<int> lens(n + 1, 1);
		queue<int> bfs;
		for (int i = 1; i <= n; ++i)
		{
			if (counts_front[i] == 0)
				bfs.push(i);
		}
		while (!bfs.empty())
		{
			int u = bfs.front();
			bfs.pop();
			for (int v = 1; v <= n; ++v)
			{
				if (!grid[u][v])
					continue;
				lens[v] = std::max(lens[v], lens[u] + 1);
				if (--counts_front[v] == 0)
					bfs.push(v);
			}
		}

		int ans = *std::max_element(lens.begin(), lens.end());
		cout << ans << endl;
	}

	// static 

	// static 
};

/*-----------------------------------main-----------------------------------*/
int main()
{
	#ifdef Shimu_Guyue
		freopen(".test/test.in" , "r", stdin );
		freopen(".test/test.out", "w", stdout);
	#endif
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int t = 1;
	if (ShimuGuyue::MULTIPLE_TESTS)
		cin >> t;
	while (t--)
	{
		ShimuGuyue::Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}