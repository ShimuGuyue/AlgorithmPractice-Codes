#include <iostream>
#include <vector>

int main(void)
{
    std::string s1;
    std::getline(std::cin, s1);
    std::string s2;
    std::getline(std::cin, s2);
    for (char& c : s1)
    {
        c = tolower(c);
    }
    for (char& c : s2)
    {
        if (isalpha(c))
            c = tolower(c);
    }

    int count(0);
    int index(0);
    int ans(-1);
    std::string temp;
    for (int i(0); i < s2.size(); ++i)
    {
        if (s2[i] == ' ')
        {
            if (temp == s1)
            {
                ++count;
                if (ans == -1)
                    ans = index;
            }
            index = i + 1;
            temp.clear();
        }
        else
        {
            temp += s2[i];
        }
    }
    if (temp == s1)
    {
        ++count;
        if (ans == -1)
            ans = index;
    }
    if (count == 0)
        std::cout << ans << std::endl;
    else
        std::cout << count << " " << ans << std::endl;
    return 0;
}