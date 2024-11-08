#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int Binary_Search(std::vector<int64_t>& as, int x);

int main(void)
{
    std::multiset<int> a;
    a.insert(10);
    a.insert(30);
    a.insert(40);
    a.insert(50);
    a.insert(60);
    a.insert(60);
    a.insert(20);
    a.insert(80);
    std::cout << *(--a.end());
    // for (int i : a)
    // {
    //     std::cout << i << " ";
    // }
    return 0;
}

int Binary_Search(std::vector<int64_t>& as, int x)
{
    int l(0), r(as.size()-1);
    while (l < r)
    {
        int mid((l + r + 1) / 2);
        if (as[mid] < x)
            l = mid;
        else // as[mid] >= x
            r = mid - 1;
    }
    return l;
}