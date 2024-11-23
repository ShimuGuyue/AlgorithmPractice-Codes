#include <iostream>
#include <map>

void solve(void);

int main(void)
{
	int t(1);
	//std::cin >> t;
	while (t--)
	{
		solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve(void)
{
    std::string s;
    std::cin >> s;
    std::map<char, int> counts;
    for (char c : s)
    {
        ++counts[c];
    }
    int ans(100000 * 26);
    for (std::pair<char, int> ci1 : counts)
    {
        int flag(0);
        for (std::pair<char, int> ci2 : counts)
        {
            int c1(ci1.first);
            int c2(ci2.first);
            if (c1 < c2)
                std::swap(c1, c2);
            flag += std::min(c1 - c2, c2 + 26 - c1) * ci2.second;
        }
        ans = std::min(ans, flag);
    }
    std::cout << ans << std::endl;
}