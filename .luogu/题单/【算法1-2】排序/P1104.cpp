#include <iostream>
#include <vector>
#include <algorithm>

struct Student
{
    std::string s;
    int y;
    int m;
    int d; 
    int index;
};

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<Student> students(n);
    for (int i(0); i < n; ++i)
    {
        Student& stu(students[i]);
        std::cin >> stu.s >> stu.y >> stu.m >> stu.d;
        stu.index = i;
    }
    std::sort(students.begin(), students.end(),
    [](Student a, Student b)
    {
        if (a.y != b.y)
            return a.y < b.y;
        if (a.m != b.m)
            return a.m < b.m;
        if (a.d != b.d)
            return a.d < b.d;
        return a.index > b.index;
    });
    for (Student stu : students)
    {
        std::cout << stu.s << std::endl;
    }
    return 0;
}