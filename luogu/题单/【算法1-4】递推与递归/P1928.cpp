#include <iostream>
#include <string>

std::string Decompression(std::string s);

int main(void)
{
    std::string s;
    std::cin >> s;
    std::string ans;
    int flag(0);
    std::string temp;
    for (char c : s)
    {
        if (flag == 0)
            if (c != '[')
                ans += c;
            else
                ++flag;
        else
        {
            if (c == '[')
                ++flag;
            else if (c == ']')
                --flag;

            if (flag == 0)
            {
                ans += Decompression(temp);
                temp.clear();
            }
            else
            {
                temp += c;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

std::string Decompression(std::string s)
{
    std::string num_s;
    std::string str;
    bool isNum(true);
    for (char c : s)
    {
        if (isdigit(c) && isNum)
            num_s += c;
        else
        {
            str += c;
            isNum = false;
        }
    }

    int num(std::stoi(num_s));
    std::string ans;
    while (num--)
    {
        ans += str;
    }

    // 递归解压
    std::string ans1;
    std::string temp;
    int flag(0);
    for (char c : ans)
    {
        if (flag == 0)
            if (c != '[')
                ans1 += c;
            else
                ++flag;
        else
        {
            if (c == '[')
                ++flag;
            else if (c == ']')
                --flag;

            if (flag == 0)
            {
                ans1 += Decompression(temp);
                temp.clear();
            }
            else
            {
                temp += c;
            }
        }
    }

    return ans1;
}