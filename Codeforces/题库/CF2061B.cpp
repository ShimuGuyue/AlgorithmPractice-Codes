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
	/*	2 * x + y > z*/
	int n;
	cin >> n;
	map<int, int> m;
	while (n--)
	{
		int a;
		cin >> a;
		++m[a];
	}
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		if (it->second < 2)
			continue;
		int x = it->first;
		it->second -= 2;
		auto jt = m.begin();
		while (jt != m.end())
		{
			if (jt->second == 0)
			{
				++jt;
				continue;
			}

			int y = jt->first;
			if (jt->second >= 2)
			{
				cout << x << " " << x << " " << y << " " << y << endl;
				return;
			}

			auto kt = jt;
			++kt;
			if (kt == m.end())
			{
				++jt;
				continue;
			}
			if (kt->second == 0)
				++kt;
			int z = kt->first;
			if (x * 2 + y <= z)
			{
				++jt;
				continue;
			}
			cout << x << " " << x << " " << y << " " << z << endl;
			return;
			++jt;
		}
		it->second += 2;
	}
	cout << -1 << endl;
}