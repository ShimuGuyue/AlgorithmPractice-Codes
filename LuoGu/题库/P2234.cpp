#include <iostream>
#include <set>
#include <algorithm>
#include <climits>

int main(void)
{
    int n;
    std::cin >> n;
    std::set<int> t;
    t.insert( 10000000); /*谁能告诉我为啥用 INT_MAX 和 INT_MAX 会 WA 三个点啊？呜呜~*/
    t.insert(-10000000);
    int ans(0);
    while (n--)
    {
        int a;
        std::cin >> a;
        if (t.size() == 2)
        {
            ans += a;
        }
        else
        {
            std::set<int>::iterator it(t.lower_bound(a));
            if (*it != a)
            {
                std::set<int>::iterator jt(it);
                --jt;
                ans += std::min(abs(*jt - a), abs(*it - a));
            }
        }
        t.insert(a);
    }
    std::cout << ans << std::endl;
    return 0;
}