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
using std::to_string;
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
	vector<vector<int>> bs(n + 1, vector<int>(n));
	int start = 1e9;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> bs[i][j];
			if (i == 1)
				start = std::min(start, bs[i][j]);
		}
	}

	vector<vector<int>> grid(n + 1, vector<int>(n + 1));
	grid[1][1] = start;
	for (int i = 2; i <= n; ++i)
	{
		priority_queue<int, vector<int>, std::greater<int>> h;
		for (int k = 0; k < n; ++k)
		{
			h.push(bs[i][k]);
		}
		int j = 1;
		while (h.size())
		{
			int top = h.top();
			h.pop();
			if (top >= grid[i-1][j-1] && top >= grid[i-1][j])
			{
				grid[i][j++] = top;
			}
			if (j > i)
				break;
		}
		if (j <= i)
		{
			cout << i - 1 << endl;
			return;
		}
	}
	cout << n << endl;
}