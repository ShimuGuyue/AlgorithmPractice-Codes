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

/*----------------------------------struct----------------------------------*/

struct Node
{
	int father;
	int rank;

	Node()
	{}
	Node(int i) : father(i), rank(1)
	{}
};

struct DisjointSet
{
	vector<Node> nodes;

	DisjointSet(int n) : nodes(n + 1)
	{
		for (int i = 1; i <= n; ++i)
		{
			nodes[i] = Node(i);
		}
	}

	int FintSet(int x)
	{
		return nodes[x].father == x ? x : nodes[x].father = FintSet(nodes[x].father);
	}

	void Merge(int x, int y)
	{
		int set_x = FintSet(x);
		int set_y = FintSet(y);
		if (nodes[set_x].rank > nodes[set_y].rank)
			nodes[set_y].father = nodes[set_x].father;
		else
			nodes[set_x].father = nodes[set_y].father;
		if (nodes[set_x].rank == nodes[set_y].rank)
			++nodes[set_y].rank;
	}

	void IsSameSet(int x, int y)
	{
		cout << (FintSet(x) == FintSet(y) ? "Yes" : "No") << endl;
	}
};

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
	int n, m, p;
	cin >> n >> m >> p;
	DisjointSet ds(n);
	while (m--)
	{
		int i, j;
		cin >> i >> j;
		ds.Merge(i, j);
	}
	while (p--)
	{
		int i, j;
		cin >> i >> j;
		ds.IsSameSet(i, j);
	}
}