#include<bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const int INF = 1e9;
const db eps = 1e-4;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;
const int N = 2e5 + 5;
int f[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
//int f[8][2] = {2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1};
int a[N], b[N], n;

// struct node {
// 	int x, y, st, flag;
// }cur, nex;

bool check(int x) {
	for (int i = 0; i < n; i++) 
	{
		b[i] = max(0, a[i] - x);
	}
	int sum1 = x, sum2 = x;
	for (int i = 0; i < n - 1; i++) 
	{
		if (b[i - 1] && b[i]) {
			int y = min(b[i - 1], b[i]);
			if (sum2 > y) {
				sum2 -= y;
				b[i] -= y;
				b[i - 1] -= y;
			} else {
				b[i] -= sum2;
				b[i - 1] -= sum2;
				sum2 = 0;
				break;
			}
		}
	}
	sum1 += sum2;
	for (int i = 0; i < n; i++) {
        sum1 -= b[i];
	}
	return sum1 >= 0;
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 1, r = 1e9;
	while (l < r) 
	{
		int mid = (l + r) / 2;
		if (check(mid)) 
		{
			r = mid;
		}
		else 
		{
			l = mid + 1;
		}
	}
	cout << l;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1; //cin >> t;
	while (t--) solve();
	return 0;
}