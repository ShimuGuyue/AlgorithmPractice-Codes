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
	int n;
	cin >> n;
	vector<int> as(n);
	for (int &a : as)
	{
		cin >> a;
	}
	sort(as.begin(), as.end());
	n /= 2;
	vector<int> bs(as.begin() + n, as.end());
	as.resize(n);

	int mid1, mid2;
	if (n & 1)
	{
		mid1 = as[n / 2];
		mid2 = bs[n / 2];
	}
	else
	{
		mid1 = (as[n / 2 - 1] + as[n / 2]) / 2;
		mid2 = (bs[n / 2 - 1] + bs[n / 2]) / 2;
	}

	int64_t ans = 1e18;
	for (int flag1 : {mid1 - 1, mid1})
	{
		for (int flag2 : {mid2, mid2 + 1})
		{
			if (flag1 == flag2)
				continue;
			int64_t count = 0;
			for (int a : as)
			{
				count += abs(a - flag1);
			}
			for (int b : bs)
			{
				count += abs(b - flag2);
			}
			ans = std::min(ans, count);
		}
	}
	cout << ans << endl;
}