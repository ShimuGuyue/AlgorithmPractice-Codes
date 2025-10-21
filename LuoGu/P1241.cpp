#include <iostream>
#include <vector>
#include <stack>

struct Bracket
{
    int index;
    char data;
};


int main(void)
{
    std::string s;
    std::cin >> s;

    int n(s.size());
    std::vector<int> ok_match(n);

    std::stack<Bracket> k;
    for (int i(0); i < n; ++i)
    {
        char c(s[i]);
        if (c == '(' || c == '[')
        {
            k.push({ i, c });
        }
        else if (c == ')' && !k.empty() && k.top().data == '(')
        {
            ok_match[i] = 1;
            ok_match[k.top().index] = 1;
            k.pop();
        }
        else if (c == ']' && !k.empty() && k.top().data == '[')
        {
            ok_match[i] = 1;
            ok_match[k.top().index] = 1;
            k.pop();
        }
    }

    for (int i(0); i < n; ++i)
    {
        if (ok_match[i])
            std::cout << s[i];
        else
        {
            if (s[i] == '(' || s[i] == ')')
                std::cout << "()";
            else if (s[i] == '[' || s[i] == ']')
                std::cout << "[]";
        }
    }
    std::cout << std::endl;

    return 0;
}