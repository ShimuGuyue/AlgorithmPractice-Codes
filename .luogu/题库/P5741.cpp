#include <iostream>
#include <vector>

struct Student
{
    std::string name;
    int a;
    int b;
    int c;
    int sum;
};


int main(void)
{
    int n;
    std::cin >> n;
    std::vector<Student> stus(n);
    for (Student& stu : stus)
    {
        std::cin >> stu.name >> stu.a >> stu.b >> stu.c;
        stu.sum = stu.a + stu.b + stu.c;
    }
    for (int i(0); i < n; ++i)
    {
        for (int j(i + 1); j < n; ++j)
        {
            if (abs(stus[i].a - stus[j].a) <= 5 &&
                abs(stus[i].b - stus[j].b) <= 5 &&
                abs(stus[i].c - stus[j].c) <= 5 &&
                abs(stus[i].sum - stus[j].sum) <= 10 )
                std::cout << stus[i].name << " " << stus[j].name << std::endl;
        }
    }
    return 0;
}