#include <iostream>
#include <set>

int main() 
{
    std::multiset<int> hs;
    int n, b;
    std::cin >> n >> b;
    while (n--)
    {
        int h;
        std::cin >> h;
        hs.insert(h);
    }
    int sum(0);
    int ans(0);
    for (std::multiset<int>::reverse_iterator it(hs.rbegin()); it != hs.rend(); ++it)
    {
        sum += *it;
        ++ans;
        if (sum >= b)
            break;
    }
    std::cout << ans << std::endl;
	return 0;
}