#include <bits/stdc++.h>

using namespace std;
int const N = 1e4 + 10;
int q[N];
vector<int> a;
int n, k; 
void quick_sort(int q[], int l, int r)
{
    int i = l - 1, j = r + 1, x = q[(l + r) / 2];
    if (l >= r) return;
    while (i < j)
    {
        do i ++; while (q[i] < x);
        do j --; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
    
}
int main()
{
    int i;
    set<int> s;
    cin >> n >> k;
    for (i = 0; i < n; i ++)
    cin >> q[i];
    quick_sort(q, 0, n - 1);
    for (i = 0; i < n; i ++)
    {
        if (!s.count(q[i]))
        {
            a.push_back(q[i]);
            s.insert(q[i]);
        }
    }
    if (k <= a.size()) cout << a[k - 1];
    else cout << "NO result";
}