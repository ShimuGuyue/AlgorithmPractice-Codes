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
	int id, m;
	cin >> id >> m;
	cout << id << " " << (m + 1) / 2 << endl;
	priority_queue<int, vector<int>, std::less<int>   > smallers;
	priority_queue<int, vector<int>, std::greater<int>> greaters;
	vector<int> as(m + 1);
	for (int i = 1; i <= m; ++i)
	{
		cin >> as[i];
	}
	int count = 1;
	cout << as[1] << " ";
	smallers.push(as[1]);
	for (int i = 2;i <= m; ++i)
	{

		if (as[i] > smallers.top())
		{
			greaters.push(as[i]);
		}
		else
		{
			smallers.push(as[i]);
		}

		if (smallers.size() > greaters.size() + 1)
		{
			greaters.push(smallers.top());
			smallers.pop();
		}
		else
		if (greaters.size() > smallers.size() + 1)
		{
			smallers.push(greaters.top());
			greaters.pop();
		}

		if ((i & 1) == 0)
			continue;
		if (smallers.size() > greaters.size())
			cout << smallers.top() << " ";
		else
			cout << greaters.top() << " ";
		++count;
		if (count % 10 == 0)
			cout << endl;
	}
	if (count % 10 != 0)
		cout << endl;
}