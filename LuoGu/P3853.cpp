#include <iostream>
#include <vector>

bool Check(std::vector<int>& distances, int x, int k); 
int Binary_Search(std::vector<int>& vi, int l, int r, int k);


int main(void)
{
    int l, n, k;
    std::cin >> l >> n >> k;

    std::vector<int> locs(n);
    std::vector<int> distances(n - 1);
    for (int i(0); i < n; ++i)
    {
        std::cin >> locs[i];
    }
    for (int i(0); i < n - 1; ++i)
    {
        distances[i] = locs[i + 1] - locs[i];
    }

    int ans(Binary_Search(distances, 1, l, k));
    std::cout << ans << std::endl;

    return 0;
}

bool Check(std::vector<int>& distances, int x, int k)
{
    int sum(0);
    for (int distance : distances)
    {
        if (x == 0)
            continue;
        sum += distance % x ? (distance / x) : (distance / x - 1);
    }
    return sum <= k;
}

int Binary_Search(std::vector<int>& vi, int l, int r, int k)
{
    while (l < r)
    {
        int mid((l + r) / 2);
        if (Check(vi, mid, k))
            r = mid;
        else
            l = mid + 1;   
    }
    return r; 
}