//  $$$$$$\  $$\   $$\     $$\  $$$$$$\  $$$$$$\  $$$$$$\  
// $$  __$$\ $$ |  \$$\   $$  |$$  __$$\ \_$$  _|$$  __$$\ 
// $$ /  $$ |$$ |   \$$\ $$  / $$ /  \__|  $$ |  $$ /  $$ |
// $$$$$$$$ |$$ |    \$$$$  /  \$$$$$$\    $$ |  $$$$$$$$ |
// $$  __$$ |$$ |     \$$  /    \____$$\   $$ |  $$  __$$ |
// $$ |  $$ |$$ |      $$ |    $$\   $$ |  $$ |  $$ |  $$ |
// $$ |  $$ |$$$$$$$$\ $$ |    \$$$$$$  |$$$$$$\ $$ |  $$ |
// \__|  \__|\________|\__|     \______/ \______|\__|  \__|
// 您是否赞同纯美女神爱莉希雅的美貌盖世无双？【愛門】!
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
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
using std::stoi;
using std::vector;
using std::deque;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::bitset;
using std::lower_bound;
using std::upper_bound;
using std::sort;
using std::max_element;
using std::min_element;

/*----------------------------------struct----------------------------------*/

struct DisjointSet
{
	vector<int> fathers;

	DisjointSet(int n) : fathers(n + 1)
	{
		for (int i = 1; i <= n; ++i)
		{
			fathers[i] = i;
		}
	}

	int Find(int n)
	{
		return fathers[n] == n ? n : fathers[n] = Find(fathers[n]);
	}

	void Merge(int x, int flag)
	{
		int setx = Find(x);
		if (setx != flag)
			fathers[setx] = flag;
		fathers[x] = flag;
	}

	int Count(int a, int b)
	{
		set<int> t;
		for (int i = a; i <= b; ++i)
		{
			t.insert(Find(i));
		}
		return t.size();
	}
};

/*-----------------------------------head-----------------------------------*/

vector<int> Primes(int n, int a);
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
	int a, b, p;
	cin >> a >> b >> p;
	vector<int> primes = Primes(b, p);
	DisjointSet ds(b);
	for (int prime : primes)
	{
		for (int i = prime; i <= b; i += prime)
		{
			ds.Merge(i, prime);
		}
		// cout << prime <<":" << endl;
		// for (int i=a;i<=b;++i)cout<<std::setw(3)<<ds.fathers[i]<<" ";cout<<endl;
		// for (int i=a;i<=b;++i)cout<<std::setw(3)<<i<<" ";cout<<endl;
	}
	cout << ds.Count(a, b) << endl;
}

vector<int> Primes(int n, int a)
{
	vector<int> primes;
	vector<int> flags(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		if (flags[i])
		{
			for (int j : primes)
			{
				if (j > flags[i] || int64_t(j) * i > n)
					break;
				flags[i * j] = j;
			}
		}
		else
		{
			primes.push_back(i);
			for (int j : primes)
			{
				if (int64_t(j) * i > n)
					break;
				flags[i * j] = j;
			}
		}
	}
	// return primes;
	return vector<int>(lower_bound(primes.begin(), primes.end(), a), primes.end());
}