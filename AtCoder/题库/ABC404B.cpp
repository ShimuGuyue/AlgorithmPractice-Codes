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
	vector<int> fathers;
	vector<int> ranks;

	DisjointSet()
	{}
	DisjointSet(int n) : fathers(n, 0), ranks(n, 0)
	{
		for (int i = 0; i < n; ++i)
		{
			fathers[i] = i;
		}
	}

	int Find(int x)
	{
		return fathers[x] == x ? x : fathers[x] = Find(fathers[x]);
	}

	void Merge(int x, int y)
	{
		int set_x = Find(x);
		int set_y = Find(y);
		if (ranks[set_x] < ranks[set_y])
		{
			fathers[set_x] = set_y;
		}
		else
		{
			fathers[set_y] = set_x;
			if (ranks[set_x] == ranks[set_y])
				++ranks[set_x];
		}
	}

	bool In_Same_Set(int x, int y)
	{
		return Find(x) == Find(y);
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
		int n;
		cin >> n;
		vector<string> s(n);
		cin >> s;
		string t;
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			t += str;
		}
		// /**/cout<<t<<endl;

		int ans = n * n;

		int sum1 = 0;
		string s1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				s1 += s[i][j];
			}
		}
		for (int i = 0; i < n * n; ++i)
		{
			sum1 += s1[i] != t[i];
		}
		ans = std::min(ans, sum1);
		// /* */cout<<s1<<endl;
		
		int sum2 = 0;
		string s2;
		for (int j = 0; j < n; ++j)
		{
			for (int i = n - 1; i >= 0; --i)
			{
				s2 += s[i][j];
			}
		}
		for (int i = 0; i < n * n; ++i)
		{
			sum2 += s2[i] != t[i];
		}
		ans = std::min(ans, sum2 + 1);
		// /**/cout<<s2<<endl;
		
		int sum3 = 0;
		string s3;
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = n - 1; j >= 0; --j)
			{
				s3 += s[i][j];
			}
		}
		for (int i = 0; i < n * n; ++i)
		{
			sum3 += s3[i] != t[i];
		}
		ans = std::min(ans, sum3 + 2);
		// /**/cout<<s3<<endl;

		int sum4 = 0;
		string s4;
		for (int j = n - 1; j >= 0; --j)
		{
			for (int i = 0; i < n; ++i)
			{
				s4 += s[i][j];
			}
		}
		for (int i = 0; i < n * n; ++i)
		{
			sum4 += s4[i] != t[i];
		}
		ans = std::min(ans, sum4 + 3);
		// /**/cout<<s4<<endl;

		cout << ans << endl;
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