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

#pragma region

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
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
#include <bitset>
using std::bitset;
#include <algorithm>
using std::lower_bound;
using std::upper_bound;
using std::sort;
using std::max_element;
using std::min_element;

template <typename T>
std::istream& operator>>(std::istream &in, vector<T> &v)
{
	for (T &t : v) in >> t;
	return in;
}
template <typename T>
std::ostream& operator<<(std::ostream &out, vector<T> &v)
{
	for (T &t : v) out << t << " ";
	return out;
}
#pragma endregion

/*----------------------------------solve-----------------------------------*/

class HYS
{
public:
	static void Solve(void)
	{
		int x, y;
		cin >> x >> y;
		if ((x ^ y) == 0 || (x & y) == 0)
		{
			cout << 1 << endl;
			return;
		}
		int flag_or = x | y;
		if (((flag_or ^ x) == 0 || (flag_or ^ y) == 0) || ((flag_or & x) == 0 || (flag_or & y) == 0))
		{
			cout << 2 << endl;
			return;
		}
		int flag_and = x & y;
		if (((flag_and ^ x) == 0 || (flag_and ^ y) == 0) || ((flag_and & x) == 0 || (flag_and & y) == 0))
		{
			cout << 2 << endl;
			return;
		}
		int flag_xor = x ^ y;
		if (((flag_xor ^ x) == 0 || (flag_xor ^ y) == 0) || ((flag_xor & x) == 0 || (flag_xor & y) == 0))
		{
			cout << 2 << endl;
			return;
		}
		int flag_gcd = Gcd(x, y);
		if (((flag_gcd ^ x) == 0 || (flag_gcd ^ y) == 0) || ((flag_gcd & x) == 0 || (flag_gcd & y) == 0))
		{
			cout << 2 << endl;
			return;
		}
		cout << 3 << endl;
	}

	static int Gcd(int a, int b)
	{
		return a % b ? Gcd(b, a % b) : b;
	}

	// static 
	// static 
	// static 
	// static 
};

/*-----------------------------------main-----------------------------------*/

int main(void)
{
#pragma region
	#ifdef Shimu_Guyue
		freopen("in.test" , "r", stdin );
		freopen("out.test", "w", stdout);
	#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#pragma endregion

    int t = 1;
	cin >> t;
	// cout << endl;
	while (t--)
	{ 
		HYS::Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}
