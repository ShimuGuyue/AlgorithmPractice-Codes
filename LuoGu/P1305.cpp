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
	char left;
	char right;
};

void Tranform_by_MLR(map<char, Node> &tree, char node);
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
	int n;
	cin >> n;
	map<char, Node> tree;
	char root = '\0';
	while (n--)
	{
		char a, b, c;
		cin >> a >> b >> c;
		if (root == '\0')
			root = a;
		tree[a].left = b;
		tree[a].right = c;
	}
	Tranform_by_MLR(tree, root);
}

void Tranform_by_MLR(map<char, Node> &tree, char node)
{
	cout << node;
	if (tree[node].left != '*')
		Tranform_by_MLR(tree, tree[node].left);
	if (tree[node].right != '*')
		Tranform_by_MLR(tree, tree[node].right);
}