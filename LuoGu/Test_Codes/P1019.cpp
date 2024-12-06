#include <iostream>
#include <vector>

int n;
std::vector<std::string> words;
std::vector<int> flags;
int ans;

void Dfs(std::string s);

int main(void)
{
    // int n;
    std::cin >> n;
    // std::vector<std::string> words(n);
    words = std::vector<std::string>(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> words[i];
    }
    // std::vector<int> flags(n);
    flags = std::vector<int>(n, 2);

    char c;
    std::cin >> c;

    // int ans(0);
    ans = 0;
    for (int i(0); i < n; ++i)
    {
        if (words[i].front() != c)
            continue;
        --flags[i];
        Dfs(words[i]);
        ++flags[i];
    }
    std::cout << ans << std::endl;
    return 0;
}

void Dfs(std::string s)
{
    for (int i(0); i < n; ++i)
    {
        if (!flags[i])
            continue;
        if (s.find(words[i]) != static_cast<size_t>(-1))
            continue;
        if (words[i].find(s) != static_cast<size_t>(-1))
            continue;

        std::string temp(s);
        for(int j(0); j < std::min(temp.size(), words[i].size()); ++j)
        {
            std::string back(temp.begin() + temp.size() - j, temp.end());
            std::string front(words[i].begin(), words[i].begin() + j);
            if (back == front)
                continue;
            if (back.empty())
                break;
            temp += std::string(words[i].begin() + j, words[i].end());
            break;
        }
        // std::cout << s << std::endl;
        --flags[i];
        Dfs(temp);
        ++flags[i];
        // std::cout << std::endl;
    }

    ans = std::max(ans, static_cast<int>(s.size()));
}