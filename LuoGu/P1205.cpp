#include <iostream>
#include <vector>

std::vector<std::string> t90(std::vector<std::string>& vs);
std::vector<std::string> t180(std::vector<std::string>& vs);
std::vector<std::string> t270(std::vector<std::string>& vs);
std::vector<std::string> mirror(std::vector<std::string>& vs);

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<std::string> begin(n);
    std::vector<std::string> end(n);
    for (std::string& s : begin)
    {
        std::cin >> s;
    }
    for (std::string& s : end)
    {
        std::cin >> s;
    }
    
    std::vector<std::string> temp;
    std::vector<std::string> temp2;
    temp = t90(begin);
    if (temp == end)
    {
        std::cout << 1 << std::endl;
        return 0;
    }
    temp = t180(begin);
    if (temp == end)
    {
        std::cout << 2 << std::endl;
        return 0;
    }
    temp = t270(begin);
    if (temp == end)
    {
        std::cout << 3 << std::endl;
        return 0;
    }
    temp = mirror(begin);
    if (temp == end)
    {
        std::cout << 4 << std::endl;
        return 0;
    }
    temp2 = t90(temp);
    if (temp2 == end)
    {
        std::cout << 5 << std::endl;
        return 0;
    }
    temp2 = t180(temp);
    if (temp2 == end)
    {
        std::cout << 5 << std::endl;
        return 0;
    }
    temp2 = t270(temp);
    if (temp2 == end)
    {
        std::cout << 5 << std::endl;
        return 0;
    }
    if (begin == end)
    {
        std::cout << 6 << std::endl;
        return 0;
    }
    std::cout << 7 << std::endl;
    return 0;
}

std::vector<std::string> t90(std::vector<std::string>& vs)
{
    int n(vs.size());
    std::vector<std::string> ans(vs);
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < n; ++j)
        {
            ans[i][j] = vs[n - 1 - j][i];
        }
    }
    return ans;
}

std::vector<std::string> t180(std::vector<std::string>& vs)
{
    int n(vs.size());
    std::vector<std::string> ans(vs);
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < n; ++j)
        {
            ans[i][j] = vs[n - 1 - i][n - 1 - j];
        }
    }
    return ans;
}

std::vector<std::string> t270(std::vector<std::string>& vs)
{
    int n(vs.size());
    std::vector<std::string> ans(vs);
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < n; ++j)
        {
            ans[i][j] = vs[j][n - 1 - i];
        }
    }
    return ans;
}

std::vector<std::string> mirror(std::vector<std::string>& vs)
{
    int n(vs.size());
    std::vector<std::string> ans(vs);
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < n; ++j)
        {
            ans[i][j] = vs[i][n - 1 - j];
        }
    }
    return ans;
}