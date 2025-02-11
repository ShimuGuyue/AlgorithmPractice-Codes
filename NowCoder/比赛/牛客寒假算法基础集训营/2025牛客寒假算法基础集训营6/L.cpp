//  $$$$$$\  $$\   $$\     $$\  $$$$$$\  $$$$$$\  $$$$$$\  
// $$  __$$\ $$ |  \$$\   $$  |$$  __$$\ \_$$  _|$$  __$$\ 
// $$ /  $$ |$$ |   \$$\ $$  / $$ /  \__|  $$ |  $$ /  $$ |
// $$$$$$$$ |$$ |    \$$$$  /  \$$$$$$\    $$ |  $$$$$$$$ |
// $$  __$$ |$$ |     \$$  /    \____$$\   $$ |  $$  __$$ |
// $$ |  $$ |$$ |      $$ |    $$\   $$ |  $$ |  $$ |  $$ |
// $$ |  $$ |$$$$$$$$\ $$ |    \$$$$$$  |$$$$$$\ $$ |  $$ |
// \__|  \__|\________|\__|     \______/ \______|\__|  \__|
// 你是否赞同纯美女神爱莉希雅的美貌盖世无双？【愛門】!
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <climits>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
using std::pair;
using std::string;
using std::vector;
using std::deque;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::sort;
using std::max_element;
using std::min_element;

void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
		freopen("test.in" , "r", stdin );
		freopen("test.out", "w", stdout);
	#else
	#endif

    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
	cin >> t;
	while (t--)
	{
		Solve();
		// cout << endl << "-------------------------" << endl;
	}
	return 0;
}

void Solve(void)
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	if (!(n & 1))
	{
		cout << "NO" << endl;
		return;
	}

	map<char, int> m;
	int C = 0;
	int H = 0;
	int I = 0;
	int K = 0;
	int E = 0;
	int N = 0;
	for (char c : s)
	{
		if (C == 0)
			if (c == 'C')
				C = 1;
			else
				++m[c];
		else
		if (H == 0)
			if (c == 'H')
				H = 1;
			else
				++m[c];
		else
		if (I == 0)
			if (c == 'I')
				I = 1;
			else
				++m[c];
		else
		if (C == 1)
			if (c == 'C')
				C = 2;
			else
				++m[c];
		else
		if (K == 0)
			if (c == 'K')
				K = 1;
			else
				++m[c];
		else
		if (E == 0)
			if (c == 'E')
				E = 1;
			else
				++m[c];
		else
		if (N == 0)
			if (c == 'N')
				N = 1;
			else
				++m[c];
		else
			++m[c];
	}
	if (N == 0)
	{
		cout << "NO" << endl;
		return;
	}

	n -= 7;
	for (auto [k, v] : m)
	{
		if (v > n / 2)
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}