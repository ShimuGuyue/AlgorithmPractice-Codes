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
	int father = 0;
	int left = 0;
	int right = 0;
};

void Insert(map<int, Node> &tree, int node, int child);
pair<int, int> Deepth_and_Width(map<int, Node> &tree);
void Length(map<int, Node> &tree, int node, int target, int last, int sum, int &ans);
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
	map<int, Node> tree;
	while (--n)
	{
		int u, v;
		cin >> u >> v;
		Insert(tree, u, v);
	}

	pair<int, int> deepth_and_width = Deepth_and_Width(tree);
	cout << deepth_and_width.first << endl;
	cout << deepth_and_width.second << endl;
	int x, y;
	cin >> x >> y;
	int length;
	Length(tree, x, y, 0, 0, length);
	cout << length << endl;
}

void Insert(map<int, Node> &tree, int node, int child)
{
	if (tree[node].left == 0)
		tree[node].left = child;
	else
		tree[node].right = child;
	tree[child].father = node;
}

pair<int, int> Deepth_and_Width(map<int, Node> &tree)
{
	struct BfsData
	{
		int node;
		int deepth;
	};
	int deepth = 0;
	int width = 0;
	int deepth_last = 0;
	int width_temp = 0;
	queue<BfsData> bfs;
	bfs.push(BfsData{1, 1});
	while (!bfs.empty())
	{
		BfsData top = bfs.front();
		bfs.pop();

		if (top.deepth == deepth_last)
			++width_temp;
		else
			width_temp = 1;
		deepth = std::max(top.deepth, deepth);
		width = std::max(width_temp, width);
		deepth_last = deepth;

		if (tree[top.node].left != 0)
			bfs.push(BfsData{tree[top.node].left, top.deepth + 1});
		if (tree[top.node].right != 0)
			bfs.push(BfsData{tree[top.node].right, top.deepth + 1});
	}
	return pair<int, int>{deepth, width};
}

void Length(map<int, Node> &tree, int node, int target, int last, int sum, int &ans)
{
	if (node == target)
	{
		ans = sum;
		return;
	}

	if (tree[node].left != 0 && tree[node].left != last)
		Length(tree, tree[node].left, target, node, sum + 1, ans);
	if (tree[node].right != 0 && tree[node].right != last)
		Length(tree, tree[node].right, target, node, sum + 1, ans);
	if (tree[node].father != 0 && tree[node].father != last)
		Length(tree, tree[node].father, target, node, sum + 2, ans);
}