#include <iostream>
#include <vector>
#include <algorithm>

struct Achievement
{
    int a;
    int b;
    int c;
    int sum;
    int id;
};

bool cmp(Achievement a, Achievement b)
{
    if (a.sum != b.sum)
        return a.sum > b.sum;
    if (a.a != b.a)
        return a.a > b.a;
    return a.id < b.id;
}

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<Achievement> students(n);
    for (int i(0); i < n; ++i)
    {
        Achievement& ac(students[i]);
        std::cin >> ac.a >> ac.b >> ac.c;
        ac.sum = ac.a + ac.b + ac.c;
        ac.id = i + 1;
    }
    std::sort(students.begin(), students.end(), cmp);
    for (int i(0); i < 5; ++i)
    {
        Achievement& ac(students[i]);
        std::cout << ac.id << " " << ac.sum << std::endl;
    }
    return 0;
}