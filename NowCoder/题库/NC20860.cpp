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
	cin >> t;
	while (t--)
	{
		Solve();
		// cout << "-------------------------" << endl;
	}
	return 0;
}

void Solve(void)
{
	int64_t l, r;
	cin >> l >> r;
	stack<int> k;
	while (r)
	{
		k.push(r % 2);
		r /= 2;
	}
	vector<int> r2;
	while (k.size())
	{
		r2.push_back(k.top());
		k.pop();
	}
	vector<int> l2(r2.size());
	for (int i = l2.size() - 1; i >= 0 && l; --i)
	{
		l2[i] = l % 2;
		l /= 2;
	}
	int64_t ans = 0;
	for (int i = 0; i < r2.size(); ++i)
	{
		if (r2[i] == l2[i])
			;
		else
		{
			for (int j = i; j < r2.size(); ++j)
			{
				ans = ans * 2 + 1;
			}
			break;
		}
	}
	cout << ans << endl;
}