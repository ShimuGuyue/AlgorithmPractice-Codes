#include <iostream>
#include <stack>

std::string Infix_to_Postfix(std::string infix);
int Calculate_by_Postfix(std::string postfix);

int main(void)
{
    std::string s1;
    std::cin >> s1;
    std::string s2 = Infix_to_Postfix(s1);
    std::cout << s2 << std::endl;
    std::cout << Calculate_by_Postfix(s2) << std::endl;
    return 0;
}

std::string Infix_to_Postfix(std::string infix)
{
    infix += '#';
    std::string postfix;

    auto Priority = [](char c) -> int   // 运算符优先级
    {
        if (c == '+' || c == '-')
            return 1;
        if (c == '*' || c == '/' || c == '%')
            return 2;
        return 0;
    };

    std::string ch = ".";  // 分隔符
    int temp = 0;

    std::stack<char> k;

    for (char c : infix)
    {
        if (isdigit(c))
            temp = temp * 10 + (c - '0');
        else
        {
            if (temp)
            {
                postfix += std::to_string(temp) + ch;
                temp = 0;
            }
            if (c == '#')
            {
                while (!k.empty())
                {
                    postfix += k.top() + ch;
                    k.pop();
                }
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
            {
                while (!k.empty() && Priority(k.top()) >= Priority(c))
                {
                    postfix += k.top() + ch;
                    k.pop();
                }
                k.push(c);
            }
            else if (c == '(')
            {
                k.push(c);
            }
            else if (c == ')')
            {
                while (k.top() != '(')
                {
                    postfix += k.top() + ch;
                    k.pop();
                }
                k.pop();
            }
        }
    }
    return postfix;
}

int Calculate_by_Postfix(std::string postfix)
{
    std::stack<int> digits;

    char ch = '.';  // 分隔符

    int digit = 0;
    for (char c : postfix)
    {

        if (isdigit(c))
            digit = digit * 10 + (c - '0');
        else if (c == ch)
        {
            if (digit)
            {
                digits.push(digit);
                digit = 0;
            }
        }
        else    // 运算符
        {
            int b = digits.top(); digits.pop();
            int a = digits.top(); digits.pop();
            if (c == '+')
                digits.push(a + b);
            else if (c == '-')
                digits.push(a - b);
            else if (c == '*')
                digits.push(a * b);
            else if (c == '/')
                digits.push(a / b);
            else if (c == '%')
                digits.push(a % b);
        }
    }

    return digits.top();
}

/*
(6+7*4)/(7+5%2)*4+1*14/2+1
*/