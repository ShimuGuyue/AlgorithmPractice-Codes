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
/*
std::cin | std::cout | std::endl;
*/
#include <iomanip>
/*
std::left | std::right
std::setw | using std::setfill
std::fixed | std::setprecision
std::oct | std::dec | std::hex
std::showbase | std::uppercase
std::showpos | std::boolalpha
*/
#include <utility>
/*
std::pair
std::make_pair
std::swap
*/
#include <string>
/*
std::string
std::getline
std::to_string
std::stoi | std::stoll | std::stod
*/
#include <array>
/*
std::array;
*/
#include <vector>
/*
std::vector
*/
#include <deque>
/*
std::deque
*/
#include <list>
/*
std::list
*/
#include <stack>
/*
std::stack
*/
#include <queue>
/*
std::queue | std::priority_queue
*/
#include <set>
/*
std::set | std::multiset
*/
#include <unordered_set>
/*
std::unordered_set | std::unordered_multiset
*/
#include <map>
/*
std::map | std::multimap
*/
#include <unordered_map>
/*
std::unordered_map | std::unordered_multimap
*/
#include <iterator>
/*
std::prev
std::next
*/
#include <bitset>
/*
std::bitset
*/
#include <algorithm>
/*
std::sort | std::stable_sort | std::is_sorted
std::reverse | std::fill | std::unique
std::all_of | std::any_of | std::none_of
std::for_each
std::find | std::find_if | std::find_if_not
std::count | std::count_if
std::remove | std::remove_if
std::max | std::min |std::minmax
std::max_element | std::min_element |std::minmax_element
std::lower_bound | std::upper_bound
std::nth_element
std::prev_permutation | std::next_permutation
*/
#include <numeric>
/*
std::gcd | std::lcm
std::iota
std::accumulate | std::partial_sum
*/
#include <cstdint>
using std::int8_t, std::int16_t, std::int32_t, std::int64_t;
using std::uint8_t, std::uint16_t, std::uint32_t, std::uint64_t;
#include <climits>
#include <cmath>
/*
std::abs | std::fabs | std::llabs
std::pow | std::sqrt | std::cbrt
std::log | std::log2 | std::log10
std::ceil | std::floor | std::round | std::llround
*/
#include <random>
/*
std::mt19937; | std::mt19937_64;
*/
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



#pragma region stlexpend
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
        out << q.front();
        q.pop();
        if (!q.empty())
            out << ' ';
    }
    return out;
}
//* std::stack
template <typename T>
std::ostream& operator<<(std::ostream &out, std::stack<T> &k)
{
    while (!k.empty())
    {
        out << k.top();
        k.pop();
        if (!k.empty())
            out << ' ';
    }
    return out;
}
//* std::priority_queue
template <typename T>
std::ostream& operator<<(std::ostream &out, std::priority_queue<T> &h)
{
    while (!h.empty())
    {
        out << h.top();
        h.pop();
        if (!h.empty())
            out << ' ';
    }
    return out;
}

// *====================
// *运算符拓展
// *====================

//* std::vector
template<typename T, typename K>
void operator+=(std::vector<T> &v, const K &k)
{
    v.push_back(static_cast<T>(k));
}
template<typename T, typename K>
void operator+=(std::vector<T> &vt, const std::vector<K> &vk)
{
    for (const K &k : vk)
    {
        vt.push_back(static_cast<T>(k));
    }
}
template<typename T>
void operator++(std::vector<T> &v, int)
{
    v.emplace_back();
}
template<typename T>
void operator--(std::vector<T> &v, int)
{
    v.pop_back();
}
template<typename T>
void operator++(std::vector<T> &v)
{
    v.emplace_back();
    for (size_t i = v.size() - 1; i > 0; --i)
    {
        std::swap(v[i], v[i - 1]);
    }
}

//* std::string
void operator++(std::string &s)
{
    s = " " + s;
}

//* std::queue
template <typename T>
void operator+=(std::queue<T> &q, const T& t)
{
    q.push(t);
}
template<typename T>
void operator--(std::queue<T> &q, int)
{
    q.pop();
}

//* std::stack
template <typename T>
void operator+=(std::stack<T> &k, const T& t)
{
    k.push(t);
}
template<typename T>
void operator--(std::stack<T> &k, int)
{
    k.pop();
}

//* std::set
template <typename T>
void operator+=(std::set<T> &st, const T& t)
{
    st.insert(t);
}
template <typename T>
void operator-=(std::set<T> &st, const T& t)
{
    st.erase(t);
}

//* std::multiset
template <typename T>
void operator+=(std::multiset<T> &st, const T& t)
{
    st.insert(t);
}
template <typename T>
void operator-=(std::multiset<T> &st, const T& t)
{
    st.erase(st.find(t));
}
}
#pragma endregion



#pragma region variable
namespace hys_variable
{

constexpr int mod1 = 1000000007;
constexpr int mod2 = 998244353;

enum directions{X, Y};

constexpr std::array<std::array<int, 2>, 9> dxy{std::array<int, 2>
    {0, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

const std::string yes  = "yes";
const std::string yes1 = "Yes";
const std::string yes2 = "YES";
const std::string no   = "no" ;
const std::string no1  = "No" ;
const std::string no2  = "NO" ;

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
std::pair<std::vector<int>, std::vector<bool>> primeSieve(const int n)
{
    std::vector<int> primes;
    std::vector<bool> isprime(n + 1);
    std::vector<int> digits(n + 1); // 标记为 0 为质数
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

std::vector<int> manacher(std::string &s)
{
    int n = s.size();
    int l = -1, r = -1, p = -1;
    std::vector<int> lens(n);
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
using namespace hys::hys_fasterio;
using namespace hys::hys_stlexpend;
using namespace hys::hys_variable;
using namespace hys::hys_function;
using namespace hys::hys_struct;
using namespace hys::hys_nickname;
using namespace hys::hys_rand;



#pragma region local_debug
#ifdef SHIMUGUYUE



void fileIO()
{
    freopen(".test/test.in" , "r", stdin );
    freopen(".test/test.out", "w", stdout);
}

template<typename... Args>
void debugPrint(const Args&... args)
{
    std::cout << '[';
    std::string separator = "";
    ((std::cout << separator << args, separator = " "), ...);
    std::cout << ']';
}
template<typename... Args>
void debug(const Args&... args) 
{
    debugPrint(args...);
}
template<typename... Args>
void debug_(const Args&... args) 
{
    ((debug(args)), ...);
    std::cout << '\n';
}



#else
void fileIO()
{}

template<typename... Args>
void debugPrint(const Args&... args)
{}
template<typename First, typename... Rest>
void debug(const First& first, const Rest&... rest)
{}
template<typename First, typename... Rest>
void debug_(const First& first, const Rest&... rest)
{}
void debug_()
{}
#endif



#pragma endregion



#pragma endregion



#pragma region solution
/*---------------------------------solution---------------------------------*/
class ShimuGuyue
{
public:
// multiple test's init
    ShimuGuyue()
    {}
    static constexpr bool MULTIPLE_TESTS{false};
// solution
    void solve()
    {
        int n;
        std::cin >> n;

        std::vector<std::string> ss(n);
        std::cin >> ss;
        for (auto &s : ss)
        {
            int nn = s.length();
            std::string s_;
            bool find = false;
            for (int i = 1; i < nn; ++i)
            {
                if (!find && s[i - 1] > s[i])
                    find = true;
                else
                    s_ += s[i - 1];
            }
            if (find)
                s_ += s.back();
            s = s_;
        }

        std::vector<std::string> ss_;
        ss_.reserve(ss.size());
        for (auto &s : ss)
        {
            if (!s.empty())
                ss_ += s;
        }

        std::sort(ss_.begin(), ss_.end(),
        [](std::string &a, std::string &b)
        {
            return a + b < b + a;
        });
        for (auto &s : ss_)
        {
            std::cout << s;
        }
        std::cout << endl;
    }
};
#pragma endregion

#pragma region main
/*-----------------------------------main-----------------------------------*/
int main()
{
    fileIO();
    ioSpeedUp();

    ShimuGuyue shimuguyue;
    int t = 1;
    if (ShimuGuyue::MULTIPLE_TESTS)
        std::cin >> t;
    while (t--)
    {
        shimuguyue.solve();
        debug_("________________________");
    }
}
#pragma endregion