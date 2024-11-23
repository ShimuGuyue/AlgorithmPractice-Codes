#include <iostream>

int main(void)
{
    std::string s;
    int64_t n;
    std::cin >> s >> n;

    while (n > s.size())
    {
        int64_t len(s.size());
        while (len * 2 < n)
        {
            len *= 2;
        }
        n = n - len - 1;
        if (n == 0)
            n = len;
    }
    std::cout << s[n - 1] << std::endl;
    return 0;
}