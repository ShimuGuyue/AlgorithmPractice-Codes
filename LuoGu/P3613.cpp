#include <iostream>
#include <map>

int main(void)
{
    int n, q;
    std::cin >> n >> q;
    std::map<std::pair<int, int>, int> objects;
    while (q--)
    {
        int mode;
        std::cin >> mode;
        if (mode == 1)
        {
            int i, j, k;
            std::cin >> i >> j >> k;
            objects[{ i, j }] = k;
        }
        else if (mode == 2)
        {
            int i, j;
            std::cin >> i >> j;
            std::cout << objects[{ i, j }] << std::endl;
        }
    }
    return 0;
}