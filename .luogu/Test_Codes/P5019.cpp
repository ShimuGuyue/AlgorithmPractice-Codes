#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> ds(n + 1);
    for (int& d : ds)
    {
        std::cin >> d;
    }
    
    return 0;
}