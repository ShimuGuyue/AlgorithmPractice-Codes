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
	cin >> t;
	while (t--)
	{
		Solve();
		// cout << endl << "-------------------------" << endl;
	}
	return 0;
}

void Solve(void)
{
	string x;
	cin >> x;
	if (x[0] == '1')
	{
		cout << "2";
		for (int i = 1; i < x.length(); ++i)
		{
			cout << "0";
		}
		cout << endl;
	}
	else
	if (x[0] == '2')
	{
		cout << "3";
		for (int i = 1; i < x.length(); ++i)
		{
			cout << "0";
		}
		cout << endl;
	}
	else
	if (x[0] == '3')
	{
		cout << "5";
		for (int i = 1; i < x.length(); ++i)
		{
			cout << "0";
		}
		cout << endl;
	}
	else
	if (x[0] == '4')
	{
		cout << "5";
		for (int i = 1; i < x.length(); ++i)
		{
			cout << "0";
		}
		cout << endl;
	}
	else
	if (x[0] == '5')
	{
		cout << "7";
		for (int i = 1; i < x.length(); ++i)
		{
			cout << "0";
		}
		cout << endl;
	}
	else
	if (x[0] == '6')
	{
		cout << "7";
		for (int i = 1; i < x.length(); ++i)
		{
			cout << "0";
		}
		cout << endl;
	}
	else
	if (x[0] == '7')
	{
		cout << "11";
		for (int i = 1; i < x.length(); ++i)
		{
			cout << "0";
		}
		cout << endl;
	}
	else
	if (x[0] == '8')
	{
		cout << "11";
		for (int i = 1; i < x.length(); ++i)
		{
			cout << "0";
		}
		cout << endl;
	}
	else
	if (x[0] == '9')
	{
		cout << "11";
		for (int i = 1; i < x.length(); ++i)
		{
			cout << "0";
		}
		cout << endl;
	}
}