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
	char data;
	Node* left = nullptr;
	Node* right = nullptr;
};

void Build_by_RM(string m, string r, Node *node);
void Traverse_by_MLR(Node* node);
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
	string m;
	string r;
	cin >> m;
	cin >> r;
	Node* root = new Node;
	Build_by_RM(m, r, root);
	Traverse_by_MLR(root);
}

void Build_by_RM(string m, string r, Node *node)
{
	node->data = r.back();
	int loc = m.find(r.back());
	if (loc != 0)
	{
		Node *left = new Node;
		node->left = left;
		string m_new = string(m.begin(), m.begin() + loc);
		string r_new = string(r.begin(), r.begin() + loc);
		Build_by_RM(m_new, r_new, left);
	}
	if (loc != m.size() - 1)
	{
		Node *right = new Node;
		node->right = right;
		string m_new = string(m.begin() + loc + 1, m.end());
		string r_new = string(r.begin() + loc, r.end() - 1);
		Build_by_RM(m_new, r_new, right);
	}
}

void Traverse_by_MLR(Node* node)
{
    cout << node->data;
    if (node->left != nullptr)
        Traverse_by_MLR(node->left);
    if (node->right != nullptr)
        Traverse_by_MLR(node->right);
}