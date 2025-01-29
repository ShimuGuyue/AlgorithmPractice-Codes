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
	int n;
	cin >> n;
	cout << "Yes" << endl;
	if (n == 1)
	{
		cout << "1 2 3 1" << endl;
	}
	else
	if (n == 2)
	{
		cout << "1 2 4 5 6 3 5 2 3 1" << endl;
	}
	else
	if (n == 3)
	{
		cout << "1 2 4 7 8 9 10 6 9 5 8 4 5 6 3 5 2 3 1" << endl;
	}
	else
	if (n == 4)
	{
		cout << "1 2 4 7 11 12 13 14 15 10 14 9 13 8 12 7 8 9 10 6 9 5 8 4 5 6 3 5 2 3 1" << endl;
	}
	else
	if (n == 5)
	{
		cout << "1 2 4 7 11 16 17 18 19 20 21 15 20 14 19 13 18 12 17 11 12 13 14 15 10 14 9 13 8 12 7 8 9 10 6 9 5 8 4 5 6 3 5 2 3 1" << endl;
	}
	else
	if (n == 6)
	{
		cout << "1 2 4 7 11 16 22 23 24 25 26 27 28 21 27 20 26 19 25 18 24 17 23 16 17 18 19 20 21 15 20 14 19 13 18 12 17 11 12 13 14 15 10 14 9 13 8 12 7 8 9 10 6 9 5 8 4 5 6 3 5 2 3 1" << endl;
	}
	else
	if (n == 7)
	{
		cout << "1 2 4 7 11 16 22 29 30 31 32 33 34 35 36 28 35 27 34 26 33 25 32 24 31 23 30 22 23 24 25 26 27 28 21 27 20 26 19 25 18 24 17 23 16 17 18 19 20 21 15 20 14 19 13 18 12 17 11 12 13 14 15 10 14 9 13 8 12 7 8 9 10 6 9 5 8 4 5 6 3 5 2 3 1" << endl;
	}
}