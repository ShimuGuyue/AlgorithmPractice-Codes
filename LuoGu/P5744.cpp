#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    while (n--)
    {
        std::string name;
        int age;
        int grade;
        std::cin >> name >> age >> grade;
        std::cout << name << " " << age + 1 << " " << (grade * 1.2 > 600 ? 600 : grade * 1.2) <<
    }
    return 0;
}