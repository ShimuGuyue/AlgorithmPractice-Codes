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
		// cout << endl;
	}
	return 0;
}

void Solve(void)
{
    int n;
    cin >> n;
    map<string, int> m;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string name;
            int score;
            cin >> name >> score;
            m[name] = score;
            cout << "OK" << endl;
        }
        else if (op == 2)
        {
            string name;
            cin >> name;
            auto it = m.find(name);
            if (it == m.end())
                cout << "Not found" << endl;
            else
                cout << it->second << endl;
        }
        else if (op == 3)
        {
            string name;
            cin >> name;
            auto it = m.find(name);
            if (it == m.end())
                cout << "Not found" << endl;
            else
            {
                cout << "Deleted successfully" << endl;
                m.erase(it);
            }
        }
        else if (op == 4)
        {
            cout << m.size() << endl;
        }
    }
}