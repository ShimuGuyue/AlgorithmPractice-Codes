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
using std::set;
using std::map;
using std::sort;
using std::max_element;
using std::min_element;

struct Node
{
	int data;
	int left = 0;
	int right = 0;
	int father = 0;
};

int n;
vector<Node> peoples;
int ans;

void Dfs(int node, int last, int &sum, int length);
void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
		freopen("test.in" , "r", stdin );
		freopen("test.out", "w", stdout);
	#else
		#define RUN_TIME
	#endif

    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
	// cin >> t;
	while (t--)
	{
		Solve();
		// cout << endl;
	}
	RUN_TIME
	return 0;
}

void Solve(void)
{
	// int n;
	cin >> n;
	// vector<Node> peoples(n + 1);
	peoples = vector<Node>(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> peoples[i].data >> peoples[i].left >> peoples[i].right;
		peoples[peoples[i].left].father = i;
		peoples[peoples[i].right].father = i;
	}
	// int ans = 1e9;
	ans = 1e9;
	for (int i = 1; i <= n; ++i)
	{
		int sum = 0;
		Dfs(i, 0, sum, 1);
		ans = sum < ans ? sum : ans;
	}
	cout << ans << endl;
}

void Dfs(int node, int last, int &sum, int length)
{
	if (peoples[node].father != 0 && peoples[node].father != last)
	{
		sum += peoples[peoples[node].father].data * length;
		Dfs(peoples[node].father, node, sum, length + 1);
	}
	if (peoples[node].left != 0 && peoples[node].left != last)
	{
		sum += peoples[peoples[node].left].data * length;
		Dfs(peoples[node].left, node, sum, length + 1);
	}
	if (peoples[node].right != 0 && peoples[node].right != last)
	{
		sum += peoples[peoples[node].right].data * length;
		Dfs(peoples[node].right, node, sum, length + 1);
	}
}