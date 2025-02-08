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
	string a;
	cin >> a;
	a = "-" + a;
	int m = a.size();
	vector<vector<int>> nexts(26, vector<int>(m)); // 直接开 'z' + 1 而不是 26 会 MLE
	vector<int> lasts(26, -1);
	for (int i = m - 1; i >= 0; --i)
	{
		for (char j = 'a'; j <= 'z'; ++j)
		{
			nexts[j - 'a'][i] = lasts[j - 'a'];
		}
		if (i != 0)
			lasts[a[i] - 'a'] = i;
	}

	int n;
	cin >> n;
	while (n--)
	{
		string b;
		cin >> b;
		int flag = 0;
		bool erase = true;
		for (char c : b)
		{
			if (nexts[c - 'a'][flag] == -1)
			{
				erase = false;
				break;
			}
			flag = nexts[c - 'a'][flag];
		}
		if (erase)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}