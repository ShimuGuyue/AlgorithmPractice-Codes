//  愛愛愛\  愛\   愛\     愛\  愛愛愛\  愛愛愛\  愛愛愛\  
// 愛  __愛\ 愛 |  \愛\   愛  |愛  __愛\ \_愛  _|愛  __愛\ 
// 愛 /  愛 |愛 |   \愛\ 愛  / 愛 /  \__|  愛 |  愛 /  愛 |
// 愛愛愛愛 |愛 |    \愛愛  /  \愛愛愛\    愛 |  愛愛愛愛 |
// 愛  __愛 |愛 |     \愛  /    \____愛\   愛 |  愛  __愛 |
// 愛 |  愛 |愛 |      愛 |    愛\   愛 |  愛 |  愛 |  愛 |
// 愛 |  愛 |愛愛愛愛\ 愛 |    \愛愛愛  |愛愛愛\ 愛 |  愛 |
// \__|  \__|\________|\__|     \______/ \______|\__|  \__|
// 你是否赞同纯美女神爱莉希雅的美貌盖世无双？【愛門】!
#include <iostream>
#include <iomanip>
#include <cstdint>
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
		// cout << endl;
	}
	return 0;
}

void Solve(void)
{
	int n;
	cin >> n;
	map<int, vector<int>> nodes;
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	int flag1 = -1, flag2 = -1;
	for (auto ivi : nodes)
	{
		if (ivi.second.size() > 2)
		{
			cout << -1 << endl;
			return;
		}
		if (ivi.second.size() == 1)
		{
			if (flag1 == -1)
				flag1 = ivi.first;
			else
				flag2 = ivi.first;
		}
	}
	cout << flag1 << " " << flag2;

}