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
	struct 
	{};
// function
public:
	static void Solve()
	{
		int n, m;
		cin >> n >> m;
		vector<bool> have('Z' + 1);
		vector<pair<char, char>> orders(m + 1);
		for (int i = 1; i <= m; ++i)
		{
			char c;
			cin >> orders[i].first >> c >> orders[i].second;
			have[orders[i].first] = have[orders[i].second] = true;
		}
		for (int ans = 1; ans <= m; ++ans)
		{
			vector<int> fronts('Z' + 1);
			vector<vector<char>> nexts('Z' + 1);
			for (int i = 1; i <= ans; ++i)
			{
				auto [u, v] = orders[i];
				if (u == v)
				{
					cout << "Inconsistency found after " << ans << " relations." << endl;
					return;
				}
				nexts[u].push_back(v);
				++fronts[v];
			}

			vector<int> lens('Z' + 1);
			queue<pair<int, int>> bfs;
			for (char c = 'A'; c <= 'Z'; ++c)
			{
				if (fronts[c] == 0 && have[c])
					bfs.push({c, 1});
			}
			if (bfs.empty())
			{
				cout << "Inconsistency found after " << ans << " relations." << endl;
				return;
			}
			string range;
			while (!bfs.empty())
			{
				auto [c, len] = bfs.front();
				bfs.pop();
				range += c;

				if (len == n)
				{
					cout << "Sorted sequence determined after " << ans << " relations: " << range << "." << endl;
					return;
				}

				for (char cc : nexts[c])
				{
					--fronts[cc];
					lens[cc] = std::max(lens[cc], len + 1);
					if (fronts[cc] == 0)
						bfs.push({cc, lens[cc]});
				}
			}
			for (char c = 'A'; c <= 'Z'; ++c)
			{
				if (fronts[c])
				{
					cout << "Inconsistency found after " << ans << " relations." << endl;
					return;
				}
			}
		}
		cout << "Sorted sequence cannot be determined." << endl;
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