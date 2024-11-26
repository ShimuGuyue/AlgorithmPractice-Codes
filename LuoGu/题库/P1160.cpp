#include <iostream>
#include <vector>

struct Student
{
    int front = 0;
    int back = 0;
};


int main(void)
{
    int n;
    std::cin >> n;
    std::vector<Student> students(n + 1);
    for (int i(2); i <= n; ++i)
    {
        int k, p;
        std::cin >> k >> p;
        if (p == 0)
        {
            if (students[k].front == 0)
            {
                students[k].front = i;
                students[i].back = k;
            }
            else
            {
                students[i].front = students[k].front;
                students[students[k].front].back = i;

                students[k].front = i;
                students[i].back = k;
            }
        }
        else
        {
            if (students[k].back == 0)
            {
                students[k].back = i;
                students[i].front = k;
            }
            else
            {
                students[students[k].back].front = i;
                students[i].back = students[k].back;

                students[i].front = k;
                students[k].back = i;
            }
        }
    }

    int m;
    std::cin >> m;
    for (int i(0); i < m; ++i)
    {
        int x;
        std::cin >> x;
        if (students[x].front == 0 && students[x].back == 0)
            continue;
        if (students[x].front != 0)
            students[students[x].front].back = students[x].back;
        if (students[x].back != 0)
        students[students[x].back].front = students[x].front;
        students[x].back = 0;
        students[x].front = 0;
    }

    int i;
    for (i = 1; i <= n; ++i)
    {
        if (students[i].front == 0 && students[i].back != 0)
            break;
    }
    while (1)
    {
        std::cout << i << " ";
        if (students[i].back == 0)
            break;
        i = students[i].back;
    }
    std::cout << std::endl;
    return 0;
}