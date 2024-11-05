#include <iostream>
#include <set>

int main(void)
{
    std::set<int> ans;
    int n;
    std::cin >> n;
    while (n--)
    {
        int a;
        std::cin >> a;
        ans.insert(a);
    } 
    std::cout << ans.size() << std::endl;
    for (int i : ans)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}