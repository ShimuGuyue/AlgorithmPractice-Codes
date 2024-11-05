#include <iostream>
#include <vector>

using people = std::pair<int, std::string>;

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<people> peoples(n);
    for (people& p : peoples)
    {
        std::cin >> p.first >> p.second;
    }
    int index(0);
    while (m--)
    {
        int a, s;
        std::cin >> a >> s;
        a = (a + peoples[index].first) % 2; 
        if (a == 0)
        {
            index -= s;
            if (index < 0)
                index += n;
        }
        else // a == 1
        {
            index += s;
            if (index >= n)
                index -= n;
        }
    }
    std::cout <<peoples[index].second << std::endl;
    return 0;
}