#include <iostream>
#include <vector>

bool Check(std::vector<int> as, int m);
int Binary_Search(std::vector<int>& as, int l, int r);
void Solve(void);

int main(void)
{
    #ifndef ONLINE_JUDGE
    freopen(".in.in"  , "r", stdin );
    freopen(".out.out", "w", stdout);
    #endif
    
    int t(1);
    //std::cin >> t;
    while (t--)
    {
        Solve();
        //std::cout << std::endl;
    }
    return 0;
}

void Solve(void)
{
    int n;
    std::cin >> n;
    std::vector<int> as(n);
    int max(0);
    for (int i(0); i < n; ++i)
    {
        std::cin >> as[i];
        max = std::max(max, as[i]);
    }
    int ans(Binary_Search(as, 1, max));
    std::cout << ans << std::endl;
}

int Binary_Search(std::vector<int>& as, int l, int r)
{
    while (l < r)
    {
        int mid((l + r) / 2);
        if (Check(as, mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

bool Check(std::vector<int> as, int m)
{
    int n(as.size());
    
    for (int i(0); i < n; ++i)
    {
        as[i] = std::max(as[i] - m, 0);
    }

    int64_t count2(m);
    for (int i(1); i < n; ++i)
    {
        if (as[i-1] && as[i])
        {
            int cost(std::min(as[i-1], as[i]));
            if (cost < count2)
            {
                as[i-1] -= cost;
                as[i]   -= cost;
                count2  -= cost;
            }
            else
            {
                as[i-1] -= count2;
                as[i]   -= count2;
                count2   = 0;
                break;
            }
        }
    }

    int64_t count1(m + count2);
    for (int i(0); i < n; i++) 
    {
        count1 -= as[i];
    }
    return count1 >= 0;
}