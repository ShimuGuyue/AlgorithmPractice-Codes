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
	int64_t temp;

	temp = r;
	stack<int> kr;
	while (temp)
	{
		kr.push(temp % 2);
		temp /= 2;
	}
	int nr = kr.size();
	
	temp = l;
	stack<int> kl;
	while (temp)
	{
		kl.push(temp % 2);
		temp /= 2;
	}
	int nl = kl.size();
	vector<int> l2(nr - nl, 0);
	while (!kl.empty())
	{
		l2.push_back(kl.top());
		kl.pop();
	}

	int64_t ans = l;
	for (int i = l2.size() - 1; i >= 0; --i)
	{
		if (l2[i] == 0)
		{
			l2[i] = 1;
			int64_t temp_ans = 0;
			for (int j : l2)
			{
				temp_ans = temp_ans * 2 + j;
			}
			if (temp_ans <= r)
				ans = temp_ans;
			else
				break;
		}
	}
	cout << ans << endl;
}