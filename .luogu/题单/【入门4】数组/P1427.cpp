#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> a;
    while (1)
    {
        int aa;
        std::cin >> aa;
        if (aa == 0)
            break;
        a.push_back(aa);
    }
    for (std::vector<int>::reverse_iterator it(a.rbegin()); it != a.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}