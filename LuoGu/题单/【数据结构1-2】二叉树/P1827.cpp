/*	数组写法	*/

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

void Build_by_LM(string m, string l, vector<char>& tree, int node);
void R_Traverse(vector<char>& tree, int node);
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
	string m;
	string l;
	cin >> m;
	cin >> l;
	vector<char> tree(1 << m.size());
	Build_by_LM(m, l, tree, 0);
	R_Traverse(tree, 0);
	cout << endl;
}

void Build_by_LM(string m, string l, vector<char>& tree, int node)
{
    tree[node] = l.front();
	int loc = m.find(l.front());
	if (loc != 0)
	{
		string m_new = string(m.begin(), m.begin() + loc);
		string l_new = string(l.begin() + 1, l.begin() + loc + 1);
		Build_by_LM(m_new, l_new, tree, node * 2 + 1);
	}
	if (loc != m.size() - 1)
	{
		string m_new = string(m.begin() + loc + 1, m.end());
		string l_new = string(l.begin() + loc + 1, l.end());
		Build_by_LM(m_new, l_new, tree, node * 2 + 2);
	}
}

void R_Traverse(vector<char>& tree, int node)
{
  	if (node * 2 + 1 < tree.size() && tree[node * 2 + 1] != '\0')
        R_Traverse(tree, node * 2 + 1);
	if (node * 2 + 2 < tree.size() && tree[node * 2 + 2] != '\0')
        R_Traverse(tree, node * 2 + 2);
    cout << tree[node];
}

/*	指针写法	*/

// #include <iostream>
// #include <iomanip>
// #include <cstdint>
// #include <string>
// #include <vector>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <set>
// #include <map>
// #include <algorithm>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::fixed;
// using std::setprecision;
// using std::pair;
// using std::string;
// using std::vector;
// using std::deque;
// using std::queue;
// using std::stack;
// using std::set;
// using std::map;
// using std::sort;
// using std::max_element;
// using std::min_element;

// struct Node
// {
// 	char data = '\0';
// 	Node *left = nullptr;
// 	Node *right = nullptr;
// };

// void Build(string m, string l, Node *node);
// void R_traverse(Node* node);
// void Solve(void);

// int main(void)
// {
// 	#ifdef Shimu_Guyue
// 		freopen(".in.in"  , "r", stdin );
// 		freopen(".out.out", "w", stdout);
// 	#else
// 		#define RUN_TIME
// 	#endif

//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     int t = 1;
// 	// cin >> t;
// 	while (t--)
// 	{
// 		Solve();
// 		// cout << endl;
// 	}
// 	RUN_TIME
// 	return 0;
// }

// void Solve(void)
// {
// 	string m;
// 	string l;
// 	cin >> m;
// 	cin >> l;
// 	Node *root = new Node;
// 	Build(m, l, root);
// 	R_traverse(root);
// }

// void Build(string m, string l, Node *node)
// {
// 	node->data = l.front();
// 	int loc = m.find(l.front());
// 	if (loc != 0)
// 	{
// 		Node *left = new Node;
// 		node->left = left;
// 		string m_new = string(m.begin(), m.begin() + loc);
// 		string l_new = string(l.begin() + 1, l.begin() + loc + 1);
// 		Build(m_new, l_new, left);
// 	}
// 	if (loc != m.size() - 1)
// 	{
// 		Node* right = new Node;
// 		node->right = right;
// 		string m_new = string(m.begin() + loc + 1, m.end());
// 		string l_new = string(l.begin() + loc + 1, l.end());
// 		Build(m_new, l_new, right);
// 	}
// }

// void R_traverse(Node* node)
// {
// 	if (node->left != nullptr)
// 		R_traverse(node->left);
// 	if (node->right != nullptr)
// 		R_traverse(node->right);
// 	cout << node->data;
// 	delete node;
// }