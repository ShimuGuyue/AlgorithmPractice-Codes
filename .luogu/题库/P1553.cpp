#include <iostream>

void reverse1(std::string& s);
void reverse2(std::string& s);

int main(void)
{
    std::string s;
    std::cin >> s;
    std::string s1;
    std::string s2;
    std::string s3;
    for (char c : s)
    {
        if (s2.empty())
            if (isdigit(c))
                s1 += c;
            else
                s2 += c;
        else
            s3 += c; 
    }
    
    if (s2 == "")
    {
        reverse1(s1);
        std::cout << s1 << std::endl;
    }
    else if (s2 == ".")
    {
        reverse1(s1);
        reverse2(s3);
        std::cout << s1 << s2 << s3 << std::endl;
    }
    else if (s2 == "/")
    {
        reverse1(s1);
        reverse1(s3);
        std::cout << s1 << s2 << s3 << std::endl;
    }
    else if (s2 == "%")
    {
        reverse1(s1);
        std::cout << s1 << s2 << std::endl;
    }

    return 0;
}

void reverse1(std::string& s)
{
    if (s != "0")
    {
        while (s.back() == '0')
        {
            s.pop_back();
        }
    }
    std::string ans(s.rbegin(), s.rend());
    s = ans;
}

void reverse2(std::string& s)
{
    std::string ans(s.rbegin(), s.rend());
    if (ans != "0")
    {
        while (ans.back() == '0')
        {
            ans.pop_back();
        }
    }
    s = ans;
}