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
	struct Data
	{
		int loc = 0;
		int num = 0;
	};

	int m, n, k, l, d;
	cin >> m >> n >> k >> l >> d;
	vector<Data> rows(m);
	for (int i = 0; i < m; ++i)
	{
		rows[i].loc = i + 1;
	}
	vector<Data> cols(n);
	for (int i = 0; i < n; ++i)
	{
		cols[i].loc = i + 1;
	}

	while (d--)
	{
		int x, y, p, q;
		cin >> x >> y >> p >> q;
		if (x == p)
			++cols[std::min(y, q) - 1].num;
		if (y == q)
			++rows[std::min(x, p) - 1].num;
	}
	sort(rows.begin(), rows.end(),
	[](Data a, Data b)
	{
		return a.num > b.num;
	});
	sort(cols.begin(), cols.end(),
	[](Data a, Data b)
	{
		return a.num > b.num;
	});
	sort(rows.begin(), rows.begin() + k,
	[](Data a, Data b)
	{
		return a.loc < b.loc;
	});
	sort(cols.begin(), cols.begin() + l,
	[](Data a, Data b)
	{
		return a.loc < b.loc;
	});

	for (int i = 0; i < k; ++i)
	{
		cout << rows[i].loc << " ";
	}
	cout << endl;
	for (int i = 0; i < l; ++i)
	{
		cout << cols[i].loc << " ";
	}
	cout << endl;
}