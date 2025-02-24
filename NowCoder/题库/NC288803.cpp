//  $$$$$$\  $$\   $$\     $$\  $$$$$$\  $$$$$$\  $$$$$$\  
// $$  __$$\ $$ |  \$$\   $$  |$$  __$$\ \_$$  _|$$  __$$\ 
// $$ /  $$ |$$ |   \$$\ $$  / $$ /  \__|  $$ |  $$ /  $$ |
// $$$$$$$$ |$$ |    \$$$$  /  \$$$$$$\    $$ |  $$$$$$$$ |
// $$  __$$ |$$ |     \$$  /    \____$$\   $$ |  $$  __$$ |
// $$ |  $$ |$$ |      $$ |    $$\   $$ |  $$ |  $$ |  $$ |
// $$ |  $$ |$$$$$$$$\ $$ |    \$$$$$$  |$$$$$$\ $$ |  $$ |
// \__|  \__|\________|\__|     \______/ \______|\__|  \__|
// 您是否赞同纯美女神爱莉希雅的美貌盖世无双？【愛門】!
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
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
using std::bitset;
using std::lower_bound;
using std::upper_bound;
using std::sort;
using std::max_element;
using std::min_element;

/*----------------------------------struct----------------------------------*/

/*-----------------------------------head-----------------------------------*/

void Solve(void);

/*-----------------------------------main-----------------------------------*/

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
		// cout << "-------------------------" << endl;
	}
	return 0;
}

/*-----------------------------------body-----------------------------------*/

void Solve(void)
{
	int n, m;
	cin >> n >> m;
	vector<int64_t> as(n);
	vector<int64_t> bs(n);
	for (auto &a : as)
	{
		cin >> a;
	}
	for (auto &b : bs)
	{
		cin >> b;
	}

	vector<int64_t> min_m_sum_a_l(n);
	vector<int64_t> min_m_sum_b_r(n);
	priority_queue<int64_t> ha;
	priority_queue<int64_t> hb;
	min_m_sum_a_l.front() = as.front();
	ha.push(as.front());
	min_m_sum_b_r.back() = bs.back();
	hb.push(bs.back());
	for (int i = 1; i < n; ++i)
	{
		if (ha.size() < m)
		{
			ha.push(as[i]);
			min_m_sum_a_l[i] = min_m_sum_a_l[i - 1] + as[i];
		}
		else
		{
			if (as[i] >= ha.top())
			{
				min_m_sum_a_l[i] = min_m_sum_a_l[i - 1];
			}
			else
			{
				min_m_sum_a_l[i] = min_m_sum_a_l[i - 1] - ha.top() + as[i];
				ha.pop();
				ha.push(as[i]);
			}
		}
	}
	for (int i = n - 2; i >= 0; --i)
	{
		if (hb.size() < m)
		{
			hb.push(bs[i]);
			min_m_sum_b_r[i] = min_m_sum_b_r[i + 1] + bs[i];
		}
		else
		{
			if (bs[i] >= hb.top())
			{
				min_m_sum_b_r[i] = min_m_sum_b_r[i + 1];
			}
			else
			{
				min_m_sum_b_r[i] = min_m_sum_b_r[i + 1] - hb.top() + bs[i];
				hb.pop();
				hb.push(bs[i]);
			}
		}
	}

	int64_t ans = 1e18;
	for (int i = m - 1; i < n - m; ++i)
	{
		ans = std::min(ans, min_m_sum_a_l[i] + min_m_sum_b_r[i + 1]);
	}
	cout << ans << endl;
}