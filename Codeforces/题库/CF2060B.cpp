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
	cin >> t;
	while (t--)
	{
		Solve();
		// cout << endl;
	}
	return 0;
}

void Solve(void)
{
	int n, m;
	cin >> n >> m;
	vector<pair<std::priority_queue<int, vector<int>, std::greater<int>>, int>> cards(n);
	for (int i = 0; i < n; ++i)
	{
		cards[i].second = i + 1;
		for (int j = 0; j < m; ++j)
		{
			int card;
			cin >> card;
			cards[i].first.push(card);
		}
	}
	sort(cards.begin(), cards.end(),
	[](pair<std::priority_queue<int, vector<int>, std::greater<int>>, int> a, pair<std::priority_queue<int, vector<int>, std::greater<int>>, int> b)
	{
		return a.first.top() < b.first.top();
	});
	int max = -1;
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (cards[i].first.top() > max)
			{
				max = cards[i].first.top();
				cards[i].first.pop();
			}
			else
			{
				cout << -1 << endl;
				return;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << cards[i].second << " ";
	}
	cout << endl;
}