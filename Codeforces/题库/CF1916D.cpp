/*
/$$$$$$\  $$\   $$\     $$\  $$$$$$\  $$$$$$\  $$$$$$\  
$$  __$$\ $$ |  \$$\   $$  |$$  __$$\ \_$$  _|$$  __$$\ 
$$ /  $$ |$$ |   \$$\ $$  / $$ /  \__|  $$ |  $$ /  $$ |
$$$$$$$$ |$$ |    \$$$$  /  \$$$$$$\    $$ |  $$$$$$$$ |
$$  __$$ |$$ |     \$$  /    \____$$\   $$ |  $$  __$$ |
$$ |  $$ |$$ |      $$ |    $$\    $$ |  $$ |  $$ |  $$ |
$$ |  $$ |$$$$$$$$\ $$ |    \$$$$$$  |$$$$$$\ $$ |  $$ |
\__|  \__|\________|\__|     \______/ \______|\__|  \__|
您是否赞同纯美女神爱莉希雅的美貌盖世无双？【愛門】!
*/

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

/*----------------------------------struct----------------------------------*/

vector<vector<string>> as(100, vector<string>(100));

/*-----------------------------------head-----------------------------------*/

void Solve(void);

/*-----------------------------------main-----------------------------------*/

int main(void)
{
	#ifdef Shimu_Guyue
		freopen("test.in" , "r", stdin );
		freopen("test.out", "w", stdout);
	#else
	#endif

    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	#define endl '\n'

	as[1][1] = "1"; 
	as[3][1] = "169"; as[3][2] = "196"; as[3][3] = "961";
	for (int i = 5; i <= 99; i += 2)
	{
		for (int j = 1; j <= i - 2; ++j)
		{
			as[i][j] = as[i - 2][j] + "00";
		}

		as[i][i - 1] = "";
		as[i][i - 1] += "1";
		for (int k = 0; k < (i - 3) / 2; ++k)
			as[i][i - 1] += "0";
		as[i][i - 1] += "6";
		for (int k = 0; k < (i - 3) / 2; ++k)
			as[i][i - 1] += "0";
		as[i][i - 1] += "9";

		as[i][i] = "";
		as[i][i] += "9";
		for (int k = 0; k < (i - 3) / 2; ++k)
			as[i][i] += "0";
		as[i][i] += "6";
		for (int k = 0; k < (i - 3) / 2; ++k)
			as[i][i] += "0";
		as[i][i] += "1";
	}

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
	for (int i = 1; i <= n; ++i)
	{
		cout << as[n][i] << " ";
	}
	cout << endl;
}