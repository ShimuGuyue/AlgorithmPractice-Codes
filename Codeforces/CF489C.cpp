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
	int m, s;
	cin >> m >> s;
	if (m * 9 < s || (s == 0 && m != 1))
	{
		cout << -1 << " " << -1 << endl;
		return;
	}
	if (m == 1)
	{
		cout << s << " " << s << endl;
		return;
	}
	vector<int> max(m);
	int flag = s;
	for (int i = 0; i < m; ++i)
	{
		if (flag >= 9)
		{
			max[i] = 9;
			flag -= 9;
		}
		else
		{
			max[i] = flag;
			flag = 0;
		}
	}
	vector<int> min(m);
	for (int i = m - 1; i >= 0; --i)
	{
		if (s > 9)
		{
			min[i] = 9;
			s -= 9;
		}
		else
		{
			if (i == 0)
				min[i] = s;
			else
			{
				min[i] = s - 1;
				break;
			}
		}
	}
	if (min[0] == 0)
		min[0] = 1;
	
	for (int i :min)
	{
		cout << i;
	}
	cout << " ";
	for (int i : max)
	{
		cout << i;
	}
	cout << endl;
}