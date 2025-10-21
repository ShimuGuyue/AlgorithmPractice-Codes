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
#include <numeric>
using std::gcd;
using std::lcm;
using std::iota;
#include <cstdint>
#include <climits>
#include <cmath>
#include <random>

#ifdef Shimu_Guyue
	#include "Debug.h"
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
	struct BfsData
	{
		int x, y;
		int flagx, flagy;
	};
// function
public:
	static void Solve(int n, int m)
	{
		int dx[4] = {-1, 0, 0, 1};
		int dy[4] = {0, -1, 1, 0};

		vector<string> grid(n);
		cin >> grid;

		int x0, y0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] == 'S')
					x0 = i, y0 = j;
			}
		}

		vector<vector<pair<int, int>>> vis(n, vector<pair<int, int>>(m, {INT_MAX, INT_MAX}));
		queue<BfsData> bfs;
		bfs.push({x0, y0, 0, 0});
		vis[x0][y0] = {0, 0};
		while (!bfs.empty())
		{
			auto [x, y, flagx, flagy] = bfs.front();
			bfs.pop();

			if (abs(flagx) > 10 || abs(flagy) > 10)
				continue;
		
			for (int i = 0; i < 4; ++i)
			{
				int x_ = x + dx[i];
				int y_ = y + dy[i];
				int flagx_ = flagx;
				int flagy_ = flagy;
				Turn(x_, y_, flagx_, flagy_, n, m);
				if (grid[x_][y_] == '#' || vis[x_][y_] == pair<int, int>{flagx_, flagy_})
					continue;
				if (vis[x_][y_] != pair<int, int>{INT_MAX, INT_MAX} && vis[x_][y_] != pair<int, int>{flagx_, flagy_})
				{
					cout << "Yes" << endl;
					return;
				}
				vis[x_][y_] = {flagx_, flagy_};
				bfs.push({x_, y_, flagx_, flagy_});
			}
		}
		cout << "No" << endl;
	}

	static void Turn(int &x, int &y, int &flagx, int &flagy, int n, int m)
	{
		if (x == -1)
			x = n - 1, --flagx;
		if (x == n)
			x = 0, ++flagx;
		if (y == -1)
			y = m - 1, --flagy;
		if (y == m)
			y = 0, ++flagy;
	}

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
	int n, m;
	while (cin >> n >> m)
	{
		ShimuGuyue::Solve(n, m);
		// cout << "-------------------------" << endl;
	}
	return 0;
}