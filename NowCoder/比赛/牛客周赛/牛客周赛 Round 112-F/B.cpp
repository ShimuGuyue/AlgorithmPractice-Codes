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



namespace hys
{



#pragma region fasterio
namespace hys_fasterio
{

constexpr char endl = '\n';

void ioSpeedUp()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
}
}
#pragma endregion



#pragma region hys_stlexpend
namespace hys_stlexpend
{

//* ====================
//*	输入流运算符
//* ====================

//* std::pair
template <typename T, typename K>
std::istream& operator>>(std::istream &in, std::pair<T, K> &p)
{
	in >> p.first >> p.second;
	return in;
}
//* std::array
template <typename T, size_t N>
std::istream& operator>>(std::istream &in, std::array<T, N> &a)
{
	for (T &t : a)
	{
		in >> t;
	}
	return in;
}
//* std::vector
template <typename T>
std::istream& operator>>(std::istream &in, std::vector<T> &v)
{
	for (T &t : v)
	{
		in >> t;
	}
	return in;
}
//* std::deque
template <typename T>
std::istream& operator>>(std::istream &in, std::deque<T> &v)
{
	for (T &t : v)
	{
		in >> t;
	}
	return in;
}

//* ====================
//*	输出流运算符
//* ====================

//* std::pair
template <typename T, typename K>
std::ostream& operator<<(std::ostream &out, const std::pair<T, K> &p)
{
	out << p.first << ' ' << p.second;
	return out;
}
//* foreach_allow - array, vector, deque, set_like, map_like
template <
	typename Container,
	typename = decltype(std::begin(std::declval<Container>())),
	typename = decltype(std::end(std::declval<Container>())),
	typename = std::enable_if_t<
		!std::is_convertible_v<Container, const char *> && // 排除 C 字符串
		!std::is_same_v<Container, std::string>			   // 排除 std::string
	>
>
std::ostream &operator<<(std::ostream &out, const Container &container)
{
    bool isfirst = true;
    for (const auto &a : container)
    {
        if (isfirst)
            isfirst = false;
        else
            out << ' ';
        out << a;
    }
    return out;
}
//* std::queue
template <typename T>
std::ostream& operator<<(std::ostream &out, std::queue<T> &q)
{
	while (!q.empty())
	{
		cout << q.front();
		q.pop();
		if (!q.empty())
			cout << ' ';
	}
	return out;
}
//* std::stack
template <typename T>
std::ostream& operator<<(std::ostream &out, std::stack<T> &k)
{
	while (!k.empty())
	{
		cout << k.top();
		k.pop();
		if (!k.empty())
			cout << ' ';
	}
	return out;
}
//* std::priority_queue
template <typename T>
std::ostream& operator<<(std::ostream &out, std::priority_queue<T> &h)
{
	while (!h.empty())
	{
		cout << h.top();
		h.pop();
		if (!h.empty())
			cout << ' ';
	}
	return out;
}

// *====================
// *运算符拓展
// *====================

//* std::vector
template<typename T, typename K>
std::vector<T>& operator+=(std::vector<T> &v, const K &k)
{
	v.push_back(static_cast<T>(k));
	return v;
}
template<typename T, typename K>
std::vector<T>& operator+=(std::vector<T> &vt, const std::vector<K> &vk)
{
	for (const K &k : vk)
	{
		vt.push_back(static_cast<T>(k));
	}
	return vt;
}
template<typename T>
std::vector<T>& operator--(std::vector<T> &v, int)
{
	v.pop_back();
	return v;
}

//* std::queue
template <typename T>
std::queue<T>& operator+=(std::queue<T> &q, const T& t)
{
	q.push(t);
	return q;
}
template<typename T>
std::queue<T>& operator--(std::queue<T> &q, int)
{
	q.pop();
	return q;
}

//* std::stack
template <typename T>
std::stack<T>& operator+=(std::stack<T> &k, const T& t)
{
	k.push(t);
	return k;
}
template<typename T>
std::stack<T>& operator--(std::stack<T> &k, int)
{
	k.pop();
	return k;
}
}
#pragma endregion



#pragma region variable
namespace hys_variable
{
enum directions{X, Y};

constexpr array<array<int, 2>, 8> dxy{
	array<int, 2>{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

string yes  = "yes";
string yes1 = "Yes";
string yes2 = "YES";
string no   = "no" ;
string no1  = "No" ;
string no2  = "NO" ;
}
#pragma endregion



#pragma region struct
namespace hys_struct
{
struct Triplet
{
	int u, v, w;

	bool operator<(const Triplet &o) const
	{
		return this->w < o.w;
	}
	bool operator>(const Triplet &o) const
	{
		return this->w > o.w;
	}

	friend std::istream &operator>>(std::istream &in, Triplet &e)
	{
		in >> e.u >> e.v >> e.w;
		return in;
	}
};

template <typename T>
class ST
{
private:
	vector<vector<T>> st{};

public:
	ST()
	{}
	
	ST(const vector<T> &v)
	{
		build(v);
	}
	
private:
	// 此函数规定贡献方式
	T merge(const T a, const T b)
	{
		return std::max(a, b);
	}

public:
	void build(const vector<T> &v)
	{
		const int n = v.size();
		const int m = log2(n) + 1;
		st.assign(n, vector<T>(m));

		for (int i = 0; i < n; ++i)
		{
			st[i][0] = v[i];
		}
		for (int j = 1; j < m; ++j)
		{
			int len = 1 << (j - 1);
			for (int i = 0; i < n - (1 << j) + 1; ++i)
			{
				st[i][j] = merge(st[i][j - 1], st[i + len][j - 1]);
			}
		}
	}
	
	T query(const int l, const int r)
	{
		int power = log2(r - l + 1);
		int len = 1 << power;
		return merge(st[l][power], st[r - len + 1][power]);
	}
};

class DisjointSet
{
private:
	struct Node
	{
		size_t parent;	// 父节点
		uint32_t rank;	// 秩
	};

	vector<Node> nodes;	// 存储每个节点的信息

public:
	DisjointSet(const size_t n) : nodes(n)
	{
		for (size_t i = 0; i < n; ++i)
		{
			nodes[i] = {i, 1};
		}
	}

	size_t find(size_t x)
	{
		return (nodes[x].parent == x) ? x : (nodes[x].parent = find(nodes[x].parent));
	}

	void merge(const size_t x, const size_t y)
	{
		size_t setX = find(x);
		size_t setY = find(y);
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

class KMP
{
private:
	string pattern{};
	vector<size_t> nexts{};

public:
	KMP()
	{}
	KMP(const string &s)
	{
		build(s);
	}

public:
	void build(const string &s)
	{
		pattern = s;
		const size_t n = s.length();
		nexts.assign(n, 0);
		for (size_t i = 1; i < n; ++i)
		{
			nexts[i] = nexts[i - 1];
			while (nexts[i] > 0 && s[nexts[i]] != s[i])
			{
				nexts[i] = nexts[nexts[i] - 1];
			}
			if (s[nexts[i]] == s[i])
				++nexts[i];
		}
	}

	int32_t find(const string &text)
	{
		const size_t n = text.length();
		const size_t m = pattern.length();
		size_t i = 0, j = 0;
		while (i < n)
		{
			if (text[i] == pattern[j])
			{
				++i;
				++j;
				if (j == m)
					return i - m;
			}
			else
			{
				if (j != 0)
					j = nexts[j - 1];
				else
					++i;
			}
		}
		return -1;
	}

	vector<size_t> find_all(const string &text)
	{
		vector<size_t> indexs;

		const size_t n = text.length();
		const size_t m = pattern.length();
		size_t i = 0, j = 0;
		while (i < n)
		{
			if (text[i] == pattern[j])
			{
				++i;
				++j;
				if (j == m)
				{
					indexs.push_back(i - m);
					j = nexts[j - 1];
				}
			}
			else
			{
				if (j != 0)
					j = nexts[j - 1];
				else
					++i;
			}
		}
		return indexs;
	}
};

class KMPAM
{
public:
	struct Data
	{
		int fail{0};
		array<int, 26> nexts{};
	};

	string pattern{};
	vector<Data> automaton{};

public:
	KMPAM()
	{}
	KMPAM(string &s)
	{
		build(s);
	}
	
public:
	void build(string &s)
	{
		pattern = s;
		int n = s.length();
		automaton.assign(n + 1, {});
		
		for (int i = 1; i < n; ++i)
		{
			int fail = automaton[i - 1].fail;
			while (fail > 0 && s[fail] != s[i])
			{
				fail = automaton[fail - 1].fail;
			}
			if (s[fail] == s[i])
				++fail;
			automaton[i].fail = fail;
		}

		for (int i = 0; i <= n; ++i)
		{
			for (int index = 0; index < 26; ++index)
			{
				if (i < n && index + 'a' == s[i])
				{
					automaton[i].nexts[index] = i + 1;
				}
				else
				{
					if (i == 0)
						automaton[i].nexts[index] = 0;
					else
						automaton[i].nexts[index] = automaton[automaton[i - 1].fail].nexts[index];
				}
			}
		}
	}

	vector<int> match(string &text)
	{
		int n = text.length();
		int m = pattern.length();
		
		vector<int> indexs;
		
		int index = 0;
		for (int i = 0; i < n; ++i)
		{
			index = automaton[index].nexts[text[i] - 'a'];
			if (index == m)
				indexs.push_back(i - m + 1);
		}
		return indexs;
	}
};

class Trie
{
private:
	struct Node
	{
		array<Node*, 26> nexts{};	// 指向子节点的所有边，默认指向空
		uint32_t count_end{0};		// 在当前节点处结束的字符串个数
		uint32_t count_pass{0};		// 经过当前节点处的字符串个数
	};

	Node* root{nullptr};	// 根节点

public:
	Trie()
	{
		root = new Node;
	}
	~Trie()
	{
		auto clear = [](auto &&clear, const Node* node) -> void
		{
			for (const Node* next : node->nexts)
			{
				if (next != nullptr)
					clear(clear, next);
			}
			delete node;
		};
		clear(clear, root);
	}

public:
	void insert(const string &s)
	{
		Node* node = root;
		++root->count_pass;
		for (const char c : s)
		{
			uint8_t index = c - 'a';
			if (node->nexts[index] == nullptr)
				node->nexts[index] = new Node;
			node = node->nexts[index];
			++node->count_pass;
		}
		++node->count_end;
	}

	uint32_t count(const string &s)
	{
		Node* node = root;
		for (const char c : s)
		{
			uint8_t index = c - 'a';
			if (node->nexts[index] == nullptr || node->nexts[index]->count_pass == 0)
				return 0;
			node = node->nexts[index];
		}
		return node->count_end;
	}

	uint32_t countPre(const string &s)
	{
		Node* node = root;
		for (const char c : s)
		{
			uint8_t index = c - 'a';
			if (node->nexts[index] == nullptr || node->nexts[index]->count_pass == 0)
				return 0;
			node = node->nexts[index];
		}
		return node->count_pass;
		//	以下为统计具体字符串，替换上一行的 return 语句，函数返回值更改为 vector<string>，另需将查找失败的 return 0; 改为 return {};
		// vector<string> ans;
		// string str = s;
		// auto dfs = [&ans, &str](auto &&dfs, Node* n) -> void
		// {
		//	 if (n->count_end > 0)
		//		 ans.push_back(str);
		//	 for (uint8_t index = 0; index < 26; ++index)
		//	 {
		//		 if (n->nexts[index] == nullptr || n->nexts[index]->count_pass == 0)
		//			 continue;
		//		 str += static_cast<char>('a' + index);
		//		 dfs(dfs, n->nexts[index]);
		//		 str.pop_back();
		//	 }
		// };
		// dfs(dfs, node);
		// return ans;
	}

	void erase(const string &s)
	{
		if (count(s) == 0)
			return;
		Node* node = root;
		--root->count_pass;
		// 此代码仅删除标记而未实际删除节点，便于节点的重复利用，避免重复 new 和 delete 的时间开销
		for (const char c : s)
		{
			uint8_t index = c - 'a';
			node = node->nexts[index];
			--node->count_pass;
		}
		--node->count_end;
		// 此代码实际删除节点，减少无用节点的内存占用
		// vector<Node*> nodes{root};
		// vector<uint8_t> indexs{};
		// for (const char c : s)
		// {
		//	 uint8_t index = c - 'a';
		//	 node = node->nexts[index];
		//	 --node->count_pass;
		//	 nodes.push_back(node);
		//	 indexs.push_back(index);
		// }
		// --node->count_end;
		// for (size_t i = nodes.size() - 1; i > 0; --i)
		// {
		//	 Node* up = nodes[i-1];
		//	 Node* now = nodes[i];
		//	 if (now->count_pass != 0 || now->count_end != 0)
		//		 break;
		//	 up->nexts[indexs[i-1]] = nullptr;
		//	 delete now;
		// }
	}
};

class ACAM
{
private:
	struct Node
	{
		size_t treeid{0};			// 节点对应的树上编号
		vector<size_t> endids{};	// 节点处结束的字符串编号
		Node* fail{nullptr};		// 节点的 fail 指针指向
		array<Node*, 26> nexts{};	// 节点在 Trie 上的子节点
	};

	Node* root{nullptr};						// Trie 根节点
	vector<Node*> tree{};						// 节点集合
	vector<uint32_t> topo_countfathers{};		// 拓扑图各节点父节点个数
	vector<pair<string, size_t>> dictionary{};	// 所有字典串及其编号集合

public:
	ACAM() : root{new Node}, tree{root}
	{}

	~ACAM()
	{
		for (Node* &node : tree)
		{
			delete node;
		}
	}

public:
	void insert(const string &s)
	{
		Node* node = root;
		for (const char c : s)
		{
			const size_t index = c - 'a';
			if (node->nexts[index] == nullptr)
			{
				node->nexts[index] = new Node;
				node->nexts[index]->treeid = tree.size();
				tree.push_back(node->nexts[index]);
			}
			node = node->nexts[index];
		}
		size_t stringid = dictionary.size();
		node->endids.push_back(stringid);
		dictionary.push_back(pair<string, size_t>{s, stringid});
	}

	void build()
	{
		/* fail */
		root->fail = root;
		queue<Node*> q;
		for (size_t index = 0; index < 26; ++index)
		{
			Node* next = root->nexts[index];
			if (next != nullptr)
			{
				next->fail = root;
				q.push(next);
			}
			else
			{
				root->nexts[index] = root;
			}
		}
		while (!q.empty())
		{
			Node* node = q.front();
			q.pop();
			for (size_t index = 0; index < 26; ++index)
			{
				Node* next = node->nexts[index];
				if (next != nullptr)
				{
					next->fail = node->fail->nexts[index];
					q.push(next);
				}
				else
				{
					node->nexts[index] = node->fail->nexts[index];
				}
			}
		}

		/* topo */
		topo_countfathers.assign(tree.size(), 0);
		for (Node* &node : tree)
		{
			++topo_countfathers[node->fail->treeid];
		}
	}

	vector<uint32_t> matchEach(const string &text)
	{
		vector<uint32_t> count_matchs(tree.size());	// 树上节点匹配次数
		Node* node = root;
		for (const char c : text)
		{
			const size_t index = c - 'a';
			node = node->nexts[index];
			++count_matchs[node->treeid];
		}

		vector<uint32_t> counts(dictionary.size());	// 各字符串匹配次数
		vector<uint32_t> count_fathers = topo_countfathers;
		queue<Node*> q;
		for (Node* &n : tree)
		{
			if (count_fathers[n->treeid] == 0)
				q.push(n);
		}
		while (!q.empty())
		{
			const Node* n = q.front();
			q.pop();
			for (const size_t id : n->endids)
			{
				counts[id] = count_matchs[n->treeid];
			}
			count_matchs[n->fail->treeid] += count_matchs[n->treeid];
			if (--count_fathers[n->fail->treeid] == 0)
				q.push(n->fail);
		}
		return counts;
	}

	uint32_t matchAll(const string &text)
	{
		vector<uint32_t> counts = matchEach(text);
		return accumulate(counts.begin(), counts.end(), 0);
	}
};

class PAM
{
private:
	struct Node
	{
		array<Node*, 26> nexts{};
		Node* fail{nullptr};
		int len{0};
		int count_end{0};	// 在每个位置有多少个结束的回文串
		int count{0};		// 当前回文串出现的次数
	};

	Node* root0{nullptr};
	Node* root1{nullptr};

	string pattern{};
	Node* last{nullptr};

public:
	PAM() : root0{new Node}, root1{new Node}, last{root0}
	{
		root0->fail = root1;
		root0->len =  0;
		root1->fail = root1;
		root1->len = -1;
	}

	~PAM()
	{
		queue<Node*> q;
		q.push(root0);
		q.push(root1);
		while (!q.empty())
		{
			Node* u = q.front();
			q.pop();
			for (Node* v : u->nexts)
			{
				if (v != nullptr)
					q.push(v);
			}
			delete u;
		}
	}

public:
	void add(string &s)
	{
		for (char c : s)
		{
			add(c);
		}
	}

	void add(char c)
	{
		int loc = pattern.length();
		int index = c - 'a';
		pattern += c;
		// 延 fail 链找到要转移的位置
		while (loc - last->len - 1 < 0 || pattern[loc - last->len - 1] != c)
		{
			last = last->fail;
		}
		if (last->nexts[index] == nullptr)
		{
			Node* node = new Node;
			node->len = last->len + 2;
			last->nexts[index] = node;
			// 找到位置之后设置 fail 指针
			if (node->len == 1)
			{
				node->fail = root0;
			}
			else
			{
				Node* n = last->fail;
				while (loc - n->len - 1 < 0 || pattern[loc - n->len - 1] != c)
				{
					n = n->fail;
				}
				node->fail = n->nexts[index];
			}
			node->count_end = node->fail->count_end + 1;
		}
		// 更新模式串最后一个位置对应的树上节点
		last = last->nexts[index];
		++last->count;
	}
};
}
#pragma endregion



#pragma region function
namespace hys_function
{
// 快速幂
int64_t quickPow(int64_t base, int64_t n, const int64_t mod = INT64_MAX)
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
int64_t exgcd(const int64_t a, const int64_t b, int64_t &x, int64_t &y)
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
int64_t inv(const int64_t base, const int64_t mod)
{
	int64_t x, y;
	exgcd(base, mod, x, y);
	return (x % mod + mod) % mod;
}

// 整除向上取整
int64_t ceilDiv(const int64_t a, const int64_t b)
{
	return (a + b - 1) / b;
}

// 欧拉筛
pair<vector<int>, vector<bool>> primeSieve(const int n)
{
	vector<int> primes;
	vector<bool> isprime(n + 1);
	vector<int> digits(n + 1); // 标记为 0 为质数
	for (int i = 2; i <= n; ++i)
	{
		if (!digits[i])
		{
			isprime[i] = true;
			primes.push_back(i);
			for (int j : primes)
			{
				if (int64_t(i) * j > n)
					break;
				digits[i * j] = j;
			}
		}
		else
		{
			for (int j : primes)
			{
				if (j > digits[i] || int64_t(i) * j > n)
					break;
				digits[i * j] = j;
			}
		}
	}
	return {primes, isprime};
}

vector<int> manacher(string &s)
{
	int n = s.size();
	int l = -1, r = -1, p = -1;
	vector<int> lens(n);
	for (int i = 0; i < n; ++i)
	{
		if (i > r)
		{
			for (int len = 0; i >= len && i + len < n; ++len)
			{// 枚举的 len 为不包括中心点的拓展长度
				if (s[i - len] != s[i + len])
					break;
				lens[i] = len + 1;
			}
			l = i - lens[i] + 1;
			r = i + lens[i] - 1;
			p = i;
		}
		else
		{
			int j = 2 * p - i;
			if (j - (lens[j] - 1) > l)
			{// 完全在范围内直接对称
				lens[i] = lens[j];
			}
			else
			{// 不完全在范围内从已知安全长度开始拓展
				lens[i] = r - i + 1;
				for (int len = lens[i]; i >= len && i + len < n; ++len)
				{
					if (s[i - len] != s[i + len])
						break;
					lens[i] = len + 1;
				}
				if (i + lens[i] - 1 > r)
				{
					l = i - lens[i] + 1;
					r = i + lens[i] - 1;
					p = i;
				}
			}
		}
	}
	return lens;
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
const uint64_t seed = time(nullptr) ^ UINT64_C(1145148251982519513);
std::mt19937 rand32(seed);
std::mt19937_64 rand64(seed);
}
#pragma endregion



}
// using hys::hys_fasterio::endl;
// using hys::hys_fasterio::ioSpeedUp;
using namespace hys::hys_fasterio;
// using hys::hys_stlexpend::operator>>;
// using hys::hys_stlexpend::operator<<;
// using hys::hys_stlexpend::operator+=;
// using hys::hys_stlexpend::operator--;
using namespace hys::hys_stlexpend;
// using hys::hys_variable::directions::X;
// using hys::hys_variable::directions::Y;
// using hys::hys_variable::dxy;
// using hys::hys_variable::yes;
// using hys::hys_variable::yes0;
// using hys::hys_variable::yes1;
// using hys::hys_variable::no;
// using hys::hys_variable::no0;
// using hys::hys_variable::no1;
using namespace hys::hys_variable;
// using hys::hys_struct::Triplet;
// using hys::hys_struct::ST;
// using hys::hys_struct::DisjointSet;
// using hys::hys_struct::StringHash;
// using hys::hys_struct::KMP;
// using hys::hys_struct::KMPAM;
// using hys::hys_struct::Trie;
// using hys::hys_struct::ACAM;
// using hys::hys_struct::PAM;
using namespace hys::hys_struct;
// using hys::hys_function::quickPow;
// using hys::hys_function::exgcd;
// using hys::hys_function::inv;
// using hys::hys_function::ceilDiv;
// using hys::hys_function::primeSieve;
// using hys::hys_function::manacher;
using namespace hys::hys_function;
// using hys::hys_nickname::maxHeap;
// using hys::hys_nickname::minHeap;
using namespace hys::hys_nickname;
// using hys::hys_rand::rand32;
// using hys::hys_rand::rand64;
using namespace hys::hys_rand;



#pragma region debug



#ifdef SHIMUGUYUE



template<typename T>
void debugPrint(const T& arg) 
{
    std::cout << arg;
}
template<typename First, typename... Rest>
void debugPrint(const First& first, const Rest&... rest) 
{
    std::cout << first << ' ';
    debugPrint(rest...);
}

template<typename First, typename... Rest>
void debug(const First& first, const Rest&... rest) 
{
	std::cout << '[';
    debugPrint(first, rest...);
	std::cout << ']';
}
template<typename First, typename... Rest>
void debug_(const First& first, const Rest&... rest) 
{
    debug(first, rest...);
	std::cout << '\n';
}



#else
	#define debug
	#define debug_
#endif



#pragma endregion



#pragma endregion



#pragma region solution
/*---------------------------------solution---------------------------------*/
class ShimuGuyue
{
public:
// init
	ShimuGuyue()
	{}
// solution
	static constexpr bool MULTIPLE_TESTS{1};

	void solve()
	{
		int n;
		cin >> n;
		vector<int> as(n);
		cin >> as;
		int ans = std::max(n, *max_element(as.begin(), as.end()));
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

	ShimuGuyue shimuguyue;
	int t = 1;
	if (ShimuGuyue::MULTIPLE_TESTS)
		cin >> t;
	while (t--)
	{
		shimuguyue.solve();
		debug_("________________________");
	}
	return 0;
}
#pragma endregion