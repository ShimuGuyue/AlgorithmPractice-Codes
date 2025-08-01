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
#pragma region template
/*---------------------------------template---------------------------------*/
#pragma region HeadFile
#include <iostream>
using std::cin;
using std::cout;
// using std::endl;
#include <iomanip>
// using std::left;
// using std::right;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;
using std::oct;
using std::dec;
using std::hex;
using std::showbase;
using std::uppercase;
using std::showpos;
using std::boolalpha;
#include <utility>
using std::pair;
using std::make_pair;
using std::swap;
#include <string>
using std::string;
using std::getline;
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
// using std::prev;
// using std::next;
#include <bitset>
using std::bitset;
#include <algorithm>
using std::sort;
using std::stable_sort;
using std::is_sorted;
using std::reverse;
using std::all_of;
using std::any_of;
using std::none_of;
using std::for_each;
// using std::find;
using std::find_if;
using std::find_if_not;
// using std::count;
using std::count_if;
using std::remove;
using std::remove_if;
using std::fill;
using std::unique;
// using std::max;
// using std::min;
using std::minmax;
using std::max_element;
using std::min_element;
using std::minmax_element;
using std::lower_bound;
using std::upper_bound;
using std::nth_element;
using std::prev_permutation;
using std::next_permutation;
#include <numeric>
using std::gcd;
using std::lcm;
using std::iota;
using std::accumulate;
using std::partial_sum;
#include <cstdint>
using std::int8_t;
using std::int16_t;
using std::int32_t;
using std::int64_t;
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
#include <climits>
#include <cmath>
using std::abs;
using std::fabs;
using std::llabs;
// using std::pow;
using std::sqrt;
using std::cbrt;
using std::log;
using std::log2;
using std::log10;
using std::ceil;
using std::floor;
using std::round;
using std::llround;
#include <random>
using std::mt19937;
using std::mt19937_64;
#pragma endregion

#pragma region Debug
#ifdef SHIMUGUYUE
	#include "Debug.h"
#else
	#define Debug(...)
	#define Debug_(...)
#endif
#pragma endregion

#pragma region IO
namespace fast_io
{

constexpr char endl = '\n';

void IO_speed_up()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

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

}
using namespace fast_io;
#pragma endregion

#pragma region Variable
namespace variables
{

namespace direction_arrays
{

constexpr array<pair<int, int>, 8> dxy{
	pair<int, int>{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

enum directions{X, Y};

}
using namespace direction_arrays;

}
using namespace variables;
#pragma endregion

#pragma region Struct
namespace structs
{
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

}
using namespace structs;
#pragma endregion

#pragma region Function
namespace functions
{

int64_t Pow(int64_t base, int64_t n, int64_t mod = INT64_MAX)
{
	int64_t ans = 1;
	base %= mod;
	while (n)
	{
		if (n & 1LL)
			ans = ans * base % mod;
		base = base * base % mod;
		n >>= 1;
	}
	return ans;
}

int64_t Ceil(int64_t a, int64_t b)
{
	return a / b + static_cast<int>(a % b != 0);
}

}
using namespace functions;
#pragma endregion

#pragma region Nickname
namespace nicknames
{

template <typename T>
using maxHeap = std::priority_queue<T, std::vector<T>, std::less<T>>;
template <typename T>
using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

}
using namespace nicknames;
#pragma endregion

#pragma region Random
namespace rands
{

std::mt19937 Rand(time(nullptr) ^ 1145148251982519513);
std::mt19937_64 Rand64(time(nullptr) ^ 1145148251982519513);

}
using namespace rands;
#pragma endregion
#pragma endregion

/*-----------------------------------body-----------------------------------*/
class ShimuGuyue
{
// test case
public:
	static constexpr bool MULTIPLE_TESTS = false;
// struct
public:
	struct 
	{};
// function
public:
	static void Solve()
	{
		int n;
		cin >> n;
		vector<int> as(n * 2 + 1);
		for (int i = 1; i <= n * 2; ++i)
		{
			cin >> as[i];
		}

		vector<int64_t> pres(n * 2 + 1);
		for (int i = 1; i <= n * 2; ++i)
		{
			pres[i] = pres[i-1] + as[i];
		}

		vector<pair<int, int>> indexs(n + 1);
		for (int i = 1; i <= n * 2; ++i)
		{
			int a = as[i];
			if (indexs[a].first == 0)
				indexs[a].first = i;
			else
				indexs[a].second = i;
		}
		
		vector<int64_t> dp(n * 2 + 1);
		for (int i = 1; i <= n * 2; ++i)
		{
			dp[i] = dp[i-1];
			int a = as[i];
			auto [l, r] = indexs[a];
			if (i == r)
				dp[i] = std::max(dp[i], dp[l-1] + pres[r] - pres[l-1]);
		}
		cout << dp[n*2] << endl;
	}

	// static 
};

#pragma region main
/*-----------------------------------main-----------------------------------*/
int main()
{
	#ifdef SHIMUGUYUE
	freopen(".test/test.in" , "r", stdin );
	freopen(".test/test.out", "w", stdout);
	#endif
    IO_speed_up();

	int t = 1;
	if (ShimuGuyue::MULTIPLE_TESTS)
		cin >> t;
	while (t--)
	{
		ShimuGuyue::Solve();
		#ifdef SHIMUGUYUE
		if (ShimuGuyue::MULTIPLE_TESTS) 
			cout << "-------------------------" << endl;
		#endif
	}
	return 0;
}
#pragma endregion