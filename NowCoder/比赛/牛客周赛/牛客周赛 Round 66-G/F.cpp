// 参考教程：https://www.bilibili.com/list/watchlater?bvid=BV1o3S2YREhu&oid=113419231429234&p=4
#include <iostream>
#include <vector>
#include <deque>

namespace solve
{
	void Solve(void);
}

int main(void)
{
	int t(1);
	std::cin >> t;
	while (t--)
	{
		solve::Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve::Solve(void)
{
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    
    std::vector<int> counts(26);
    for (int i(0); i < n; ++i)
    {
        char& c(s[i]);
        ++counts[c - 'a'];
    }

    int letter_index;
    for (int i(0); i < 26; ++i)
    {
        int m(counts[i]);
        if (k > m)
            k -= m;
        else
        {
            letter_index = i;
            break;
        }
    }

    std::vector<char> next_letters(n);
    for (int i(n-2); i >= 0; --i)
    {
        if (s[i] != s[i+1])
            next_letters[i] = s[i+1];
        else
            next_letters[i] = next_letters[i+1];
    } 

    std::deque<int> ans_indexs; // move(i) 从小到大排序
    for (int i(n-1); i >= 0; --i)
    {
        if (s[i] - 'a' != letter_index)
            continue;

        if (i == n - 1)
        {
            ans_indexs.push_back(i);
        }
        else
        {
            if (s[i] < next_letters[i])
                ans_indexs.push_back(i);
            else if (s[i] > next_letters[i])
                ans_indexs.push_front(i);
        }
    }

    int loc(ans_indexs[k-1]);
    std::cout << s[loc];
    for (int i(0); i < loc; ++i)
    {
        std::cout << s[i];
    }
    for (int i(loc + 1); i < n; ++i)
    {
        std::cout << s[i];
    }
    std::cout << std::endl;
}