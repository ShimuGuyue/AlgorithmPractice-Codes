#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

struct Student
{
    std::string sex;
    double h;
};


int main(void)
{
    int n;
    std::cin >> n;
    std::vector<Student> students(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> students[i].sex >> students[i].h;
    }
    std::sort(students.begin(), students.end(),
    [](Student a, Student b)
    {
        if (a.sex != b.sex)
            return a.sex.length() < b.sex.length();
        if (a.sex == "male")
            return a.h < b.h;
        return a.h > b.h;
    });
	for (Student stu : students)
	{
		std::cout << std::fixed << std::setprecision(2) << stu.h << " ";
	}
	std::cout << std::endl;
    return 0;
}