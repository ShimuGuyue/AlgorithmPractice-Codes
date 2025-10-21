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
#include <iomanip>
#include <cstdint>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
using std::pair;
using std::string;
using std::to_string;
using std::stoi;
using std::vector;
using std::deque;
using std::list;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::bitset;
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
/*----------------------------------struct----------------------------------*/

/*-----------------------------------head-----------------------------------*/

void Solve(void);

/*-----------------------------------main-----------------------------------*/

int main(void)
{
#pragma region
	#ifdef Shimu_Guyue
		freopen("test.in" , "r", stdin );
		freopen("test.out", "w", stdout);
	#else
	#endif

    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	#define endl '\n'
#pragma endregion

    int t = 1;
	cin >> t;
	while (t--)
	{ 
		Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}
/*-----------------------------------body-----------------------------------*/

void Solve(void)
{
	int n;
	cin >> n;
	vector<int64_t> as(n + 2);
	for (int i = 1; i <= n; ++i)
	{
		cin >> as[i];
	}
	as.front() = INT_MIN;
	as.back() = INT_MAX;

	vector<int64_t> sums_ltor(n + 2);
	vector<int64_t> sums_rtol(n + 2);
	for (int i = 2; i <= n; ++i)
	{
		if (as[i] - as[i - 1] <= as[i - 1] - as[i - 2])
			sums_ltor[i] = sums_ltor[i - 1] + 1;
		else
			sums_ltor[i] = sums_ltor[i - 1] + as[i] - as[i - 1];
	}
	for (int i = n - 1; i >= 1; --i)
	{
		if (as[i + 1] - as[i] <= as[i + 2] - as[i + 1])
			sums_rtol[i] = sums_rtol[i + 1] + 1;
		else
			sums_rtol[i] = sums_rtol[i + 1] + as[i + 1] - as[i];
	}

	// cout << as << endl;
	// cout << sums_ltor << endl;
	// cout << sums_rtol << endl;

	int m;
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		if (x < y)
			cout << sums_ltor[y] - sums_ltor[x] << endl;
		else
			cout << sums_rtol[y] - sums_rtol[x] << endl;
	}
}