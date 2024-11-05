#include <iostream>

struct Student
{
    std::string name;
    int a;
    int b;
    int c;
};


int main(void)
{
    int n;
    std::cin >> n;
    Student ans;
    int max(-1);
    while (n--)
    {
        Student stu;
        std::cin >> stu.name >> stu.a >> stu.b >> stu.c;
        int sum(stu.a + stu.b + stu.c);
        if (sum > max)
        {
            max = sum;
            ans = stu;
        }
    }
    std::cout << ans.name << " " << ans.a << " " << ans.b << " " << ans.c << std::endl;
    return 0;
}