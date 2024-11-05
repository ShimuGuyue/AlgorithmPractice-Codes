#include <iostream>

int main(void)
{
    int ans[3];
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a > b)
        std::swap(a, b);
    if (a > c)
        std::swap(a, c);
    if (b > c)
        std::swap(b, c);
    std::string s;
    std::cin >> s;
    for (int i(0); i < 3; ++i)
    {
        if (s[i] == 'A')
            ans[i] = a;
        else if (s[i] == 'B')
            ans[i] = b;
        else if (s[i] == 'C')
            ans[i] = c;
    }
    std::cout << ans[0] << " " << ans[1] << " " << ans[2] << std::endl;
    return 0;
}