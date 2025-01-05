/**
 * 	80 分 WA #2 ：试试这组样例
 * 
 * 	7
 * 	4 5
 * 	3 7
 * 	0 0
 * 	2 6
 * 	0 0
 * 	0 0
 * 	0 0
 * 
 * 	4
 */
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
	int left;
	int right;
};

vector<Node> tree;
int ans;

void Dfs(Node &node, int depth);
void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
		freopen(".in.in"  , "r", stdin );
		freopen(".out.out", "w", stdout);
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
	int n;
	cin >> n;
	tree = vector<Node>(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int l, r;
		cin >> l >> r;
		tree[i].left = l;
		tree[i].right = r;
	}
	// int ans = 0;
	ans = 0;
	Dfs(tree[1], 1);
	cout << ans << endl;
}

void Dfs(Node &node, int depth)
{
	ans = std::max(ans, depth);

	if (node.left != 0)
		Dfs(tree[node.left], depth + 1);
	if (node.right != 0)
		Dfs(tree[node.right], depth + 1);
}