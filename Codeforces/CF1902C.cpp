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

/*----------------------------------struct----------------------------------*/

/*-----------------------------------head-----------------------------------*/

int Gcd(int a, int b);
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
	cin >> t;
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
	int n;
	cin >> n;
	set<int> digits;
	vector<int> as(n);
	for (auto &a : as)
	{
		cin >> a;
		digits.insert(a);
	}
	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}

	sort(as.begin(), as.end());
	vector<int> difs(n - 1);
	for (int i = 0; i < n - 1; ++i)
	{
		difs[i] = as[i+1] - as[i];
	}
	int mindif = difs[0];
	for (int i = 1; i < n - 1; ++i)
	{
		mindif = Gcd(mindif, difs[i]);
	}

	int64_t flag = as.back() - mindif;	// 不开 int64 会在 109 行爆int
	while (digits.find(flag) != digits.end())
	{
		flag -= mindif;
	}
	int64_t ans = (as.back() - flag) / mindif;
	for (auto a : as)
	{
		ans += (as.back() - a) / mindif;
	}
	cout << ans << endl;
}

int Gcd(int a, int b)
{
	return a % b == 0 ? b : Gcd(b, a % b);
}