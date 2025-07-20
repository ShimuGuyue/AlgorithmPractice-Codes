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
// https://github.com/ShimuGuyue/AlgorithmPractice-Codes
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
using std::pow;
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

#pragma region debug
#ifdef SHIMUGUYUE
	#include "debug.h"
#else
	#define debug(...)
	#define debug_(...)
#endif
#pragma endregion

#pragma region hys
namespace hys
{
#pragma region fasterio
namespace hys_fasterio
{
constexpr char endl = '\n';

void ioSpeedUp()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
}
}
#pragma endregion

#pragma region easyio
namespace hys_easyio
{
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
	for (T &t : a)
	{
		in >> t;
	}
	return in;
}
template <typename T, size_t N>
std::ostream& operator<<(std::ostream &out, const std::array<T, N> &a)
{
	for (const T &t : a)
	{
		out << t << ' ';
	}
	return out;
}

// std::vector
template <typename T>
std::istream& operator>>(std::istream &in, std::vector<T> &v)
{
	for (T &t : v)
	{
		in >> t;
	}
	return in;
}
template <typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v)
{
	for (const T &t : v)
	{
		out << t << ' ';
	}
	return out;
}

// std::deque
template <typename T>
std::istream& operator>>(std::istream &in, std::deque<T> &v)
{
	for (T &t : v)
	{
		in >> t;
	}
	return in;
}
template <typename T>
std::ostream& operator<<(std::ostream &out, const std::deque<T> &v)
{
	for (const T &t : v)
	{
		out << t << ' ';
	}
	return out;
}

// std::queue
template <typename T>
std::ostream& operator<<(std::ostream &out, std::queue<T> &q)
{
	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}
	return out;
}

// std::stack
template <typename T>
std::ostream& operator<<(std::ostream &out, std::stack<T> &k)
{
	while (!k.empty())
	{
		cout << k.top() << ' ';
		k.pop();
	}
	return out;
}

// std::priority_queue
template <typename T>
std::ostream& operator<<(std::ostream &out, std::priority_queue<T> &h)
{
	while (!h.empty())
	{
		cout << h.top() << ' ';
		h.pop();
	}
	return out;
}

// std::set*
template <typename K>
std::ostream& operator<<(std::ostream &out, const std::set<K> &t)
{
	for (const K &k : t)
	{
		out << k << ' ';
	}
	return out;
}

template <typename K>
std::ostream& operator<<(std::ostream &out, const std::multiset<K> &t)
{
	for (const K &k : t)
	{
		out << k << ' ';
	}
	return out;
}

// std::map*
template <typename K, typename V>
std::ostream& operator<<(std::ostream &out, const std::map<K, V> &m)
{
	for (const pair<K, V> &kv : m)
	{
		out << kv.first << ' ' << kv.second << '\n';
	}
	return out;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream &out, const std::multimap<K, V> &m)
{
	for (const pair<K, V> &kv : m)
	{
		out << kv.first << ' ' << kv.second << '\n';
	}
	return out;
}
}
#pragma endregion

#pragma region variable
namespace hys_variable
{
constexpr array<array<int, 2>, 8> dxy{
	array<int, 2>{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

enum directions{X, Y};
}
#pragma endregion

#pragma region struct
namespace hys_struct
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

	int find(int x)
	{
		return (nodes[x].parent == x) ? x : (nodes[x].parent = find(nodes[x].parent));
	}

	void merge(const int x, const int y)
	{
		int setX = find(x);
		int setY = find(y);
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

class StringHash 
{
private:
    uint64_t base;
    uint64_t inv_base;
    uint64_t mod;
    string s;
    vector<uint64_t> pre_hashs;
    vector<uint64_t> pows;
    vector<uint64_t> invs;

private:
    uint64_t quickPow(uint64_t base, uint64_t n)
    {
        uint64_t ans = 1;
        while (n)
        {
            if (n % 2)
                ans = ans * base % mod;
            base = base * base % mod;
            n /= 2;
        }
        return ans;
    }

public:
    StringHash(const string &str, const uint64_t mod = UINT64_C(1000000007), const uint64_t base = 131) : s(" " + str), mod(mod), base(base)
    {
        inv_base = quickPow(base, mod - 2);
        buildPreHashs();
    }

    void buildPreHashs()
    {
        const size_t n = s.length();
        pre_hashs.assign(n, 0);
        pows.assign(n, 0);
        pows[0] = 1;
        invs.assign(n, 0);
        invs[0] = 1;
        for (size_t i = 1; i < n; ++i)
        {
            pows[i] = pows[i - 1] * base % mod;
            invs[i] = invs[i - 1] * inv_base % mod;
            pre_hashs[i] = (pre_hashs[i - 1] + static_cast<uint8_t>(s[i]) * pows[i] % mod) % mod;
        }
    }

    uint64_t getHash(const size_t l, const size_t r)
    {
        return (pre_hashs[r] - pre_hashs[l - 1] + mod) % mod * invs[l - 1] % mod;
    }
};
}
#pragma endregion

#pragma region function
namespace hys_function
{
// 快速幂
int64_t quickPow(int64_t base, int64_t n, int64_t mod = INT64_MAX)
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

// 拓展欧几里得
int64_t exgcd(int64_t a, int64_t b, int64_t &x, int64_t &y)
{
	if(!b)
	{
		x = 1, y = 0;
		return a;
	}
	int64_t g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

// 逆元
int64_t 
inv(int64_t base, int64_t mod)
{
	int64_t x, y;
	exgcd(base, mod, x, y);
	return (x % mod + mod) % mod;
}

// 整除向上取整
int64_t ceilDiv(int64_t a, int64_t b)
{
	return a / b + static_cast<int>(a % b != 0);
}
}
#pragma endregion

#pragma region nickname
namespace hys_nickname
{

template <typename T>
using maxHeap = std::priority_queue<T, std::vector<T>, std::less<T>>;
template <typename T>
using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

}
#pragma endregion

#pragma region rand
namespace hys_rand
{
const uint64_t seed =time(nullptr) ^ 1145148251982519513;
std::mt19937 rand32(seed);
std::mt19937_64 rand64(seed);
}
#pragma endregion
}
// using hys::hys_easyio::operator>>;
// using hys::hys_easyio::operator<<;
using namespace hys::hys_easyio;
// using hys::hys_fasterio::endl;
// using hys::hys_fasterio::ioSpeedUp;
using namespace hys::hys_fasterio;
// using hys::hys_variable::dxy;
// using hys::hys_variable::directions::X;
// using hys::hys_variable::directions::Y;
using namespace hys::hys_variable;
// using hys::hys_struct::Edge;
// using hys::hys_struct::DisjointSet;
// using hys::hys_struct::StringHash;
using namespace hys::hys_struct;
// using hys::hys_function::quickPow;
// using hys::hys_function::exgcd;
// using hys::hys_function::inv;
// using hys::hys_function::ceilDiv;
using namespace hys::hys_function;
// using hys::hys_nickname::maxHeap;
// using hys::hys_nickname::minHeap;
using namespace hys::hys_nickname;
// using hys::hys_rand::rand32;
// using hys::hys_rand::rand64;
using namespace hys::hys_rand;
#pragma endregion

#pragma endregion

#pragma region solution
/*---------------------------------solution---------------------------------*/
class ShimuGuyue
{
public:
// test case
	static constexpr bool MULTIPLE_TESTS = 1;
// init
	ShimuGuyue()
	{}
// solution
	void solve()
	{
		int n;
		cin >> n;
		int64_t ans = 0;
		while (n--)
		{
			int64_t a, b, c, d;
			cin >> a >> b >> c >> d;
			if (b > d)
				ans += b - d + a;
			else if (a > c)
				ans += a - c;
		}
		cout << ans << endl;
	}
};
#pragma endregion

#pragma region main
/*-----------------------------------main-----------------------------------*/
int main()
{
	#ifdef SHIMUGUYUE
	freopen(".test/test.in" , "r", stdin );
	freopen(".test/test.out", "w", stdout);
	#endif
    ioSpeedUp();

	int t = 1;
	if (ShimuGuyue::MULTIPLE_TESTS)
		cin >> t;
	ShimuGuyue shimuguyue;
	while (t--)
	{
		shimuguyue.solve();
		#ifdef SHIMUGUYUE
		if (ShimuGuyue::MULTIPLE_TESTS) 
			cout << "-------------------------" << endl;
		#endif
	}
	return 0;
}
#pragma endregion