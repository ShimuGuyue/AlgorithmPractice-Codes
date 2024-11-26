#include <iostream>
#include <vector>
#include <stack>

int main(void)
{    
int q;
std::cin >> q;
while (q--)
{
    int n;
    std::cin >> n;
    std::vector<int> pushed(n);
    std::vector<int> poped(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> pushed[i];
    }
    for (int i(0); i < n; ++i)
    {
        std::cin >> poped[i];
    }

    std::stack<int> k;
    int j(0);
    for (int i(0); i < n; ++i)
    {
        k.push(pushed[i]);
        while (!k.empty() && k.top() == poped[j])
        {
            k.pop();
            ++j;
        }
    }
    while (!k.empty() && k.top() == poped[j])
    {
        k.pop();
        ++j;
    }

    std::cout << (k.empty() ? "Yes" : "No") << std::endl; 
}
    return 0;
}