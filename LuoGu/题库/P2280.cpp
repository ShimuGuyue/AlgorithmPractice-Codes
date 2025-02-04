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
	// cin >> t;
	while (t--)
	{
		Solve();
		// cout << endl << "-------------------------" << endl;
	}
	return 0;
}

void Solve(void)
{
	const int m = 5001;

	int n, r;
	cin >> n >> r;
	vector<vector<int>> grid(m, vector<int>(m));
	while (n--)
	{
		int x, y, v;
		cin >> x >> y >> v;
		grid[x][y] += v;
	}

	vector<vector<int>> sums(m, vector<int>(m));
	sums[0][0] = grid[0][0];
	for (int i = 1; i < m; ++i)
	{
		sums[i][0] = sums[i - 1][0] + grid[i][0];
	}
	for (int j = 1; j < m; ++j)
	{
		sums[0][j] = sums[0][j - 1] + grid[0][j];
	}
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + grid[i][j];
		}
	}

	int ans = sums[r - 1][r - 1];
	for (int i = r; i < m; ++i)
	{
		int sum = sums[i][r - 1] - sums[i - r][r - 1];
		ans = std::max(ans, sum);
	}
	for (int j = r; j < m; ++j)
	{
		int sum = sums[r - 1][j] - sums[r - 1][j - r];
		ans = std::max(ans, sum);
	}
	for (int i = r; i < m; ++i)
	{
		for (int j = r; j < m; ++j)
		{
			int sum = sums[i][j] - sums[i - r][j] - sums[i][j - r] + sums[i - r][j - r];
			ans = std::max(ans, sum);
		}
	}
	cout << ans << endl;
}