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

struct DisjointSet
{
	vector<int> sets;
	vector<int> ranks;

	DisjointSet()
	{}
	DisjointSet(const int &n) : sets(n), ranks(n, 1)
	{
		std::iota(sets.begin(), sets.end(), 0);
	}

	int Find_set(const int &x)
	{
		return sets[x] == x ? x : sets[x] = Find_set(sets[x]);
	}

	void Merge_set(const int &x, const int &y)
	{
		int set_x = Find_set(x);
		int set_y = Find_set(y);
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

	bool In_same_set(const int &x, const int &y)
	{
		return Find_set(x) == Find_set(y);
	}

	int Count_sets()
	{
		set<int> count;
		for (int i = 0; i < sets.size(); ++i)
		{
			count.insert(Find_set(i));
		}
		return count.size();
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

int Ceil(int a, int b)
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
#define MULTIPLE_TESTS (false)

class ShimuGuyue
{
public:	// function
	static void Solve()
	{
		int n;
		cin >> n;
		vector<int> as(n);
		cin >> as;
		vector<pair<int, int>> temp(n);
		for (int i = 0; i < n; ++i)
		{
			temp[i] = {as[i], i};
		}
		std::stable_sort(temp.begin(), temp.end());

		int ans = 1;
		int count = 0;
		vector<bool> visited(n);
		for (int i = 0; i < n; ++i)
		{
			if (temp[i].second > i)
				++count;
			if (visited[i])
				--count;
			visited[temp[i].second] = true;
			ans = std::max(ans, count);
		}
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
	#if MULTIPLE_TESTS
		cin >> t;
	#endif
	while (t--)
	{
		ShimuGuyue::Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}