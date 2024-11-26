#include <iostream>
#include <stack>

int main(void)
{
    std::string s;
    std::cin >> s;
    std::stack<int> k;
    int temp(0);
    for (char c : s)
    {
        if (isdigit(c))
            temp = temp * 10 + c - '0';
        else if (c == '.')
        {
            k.push(temp);
            temp = 0;
        }
        else if (c == '+')
        {
            int b(k.top());
            k.pop();
            int a(k.top());
            k.pop();
            int c(a + b);
            k.push(c);
        }
        else if (c == '-')
        {
            int b(k.top());
            k.pop();
            int a(k.top());
            k.pop();
            int c(a - b);
            k.push(c);
        }
        else if (c == '*')
        {
            int b(k.top());
            k.pop();
            int a(k.top());
            k.pop();
            int c(a * b);
            k.push(c);
        }
        else if (c == '/')
        {
            int b(k.top());
            k.pop();
            int a(k.top());
            k.pop();
            int c(a / b);
            k.push(c);
        }
    }
    int ans(k.top());
    std::cout << ans << std::endl;
    return 0;
}