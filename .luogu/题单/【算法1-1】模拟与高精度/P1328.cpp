#include <iostream>
#include <vector>

int battle[5][5]{
    2, 0, 1, 1, 0,  
    1, 2, 0, 1, 0,
    0, 1, 2, 0, 1,     
    0, 0, 1, 2, 1,
    1, 1, 0, 0, 2,
};

int main(void)
{
    int n, na, nb;
    std::cin >> n >> na >> nb;
    std::vector<int> a(na);
    std::vector<int> b(nb);
    for (int& i : a)
    {
        std::cin >> i;
    }
    for (int& i : b)
    {
        std::cin >> i;
    }
    int countA(0), countB(0);
    for (int i(0); i < n; ++i)
    {
        switch (battle[a[i % na]][b[i % nb]])
        {
            case 0:
                ++countB; break;
            case 1:
                ++countA; break;
        }
    }
    std::cout << countA << " " << countB << std::endl;
    return 0;
}