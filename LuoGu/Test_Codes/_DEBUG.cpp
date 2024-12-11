#include <iostream>
#include <algorithm>

void Link(std::string& s, std::string& t)
{
    int len(std::min(s.size(), t.size()));

    for (int i(1); i <= len; ++i)
    {
        std::string tail(s.end() - i, s.end());
        std::string head(t.begin(), t.begin() + i);
        if (tail == head)
        {
            s += std::string(t.begin() + i, t.end());
            break;
        }
    }
}

int main(void)
{
	// std::string s("456");
	// std::string t("123456789");
	// // std::cout << t.find(s);
	// int l(s.size());
	// std::string a = "****";
	// std::cout << std::string(t.begin(), t.begin() + t.find(s)) << a << std::string(t.begin()+t.find(s)+s.size(), t.end());
	// int len(std::min(s.size(), t.size()));
	// for (int i(1); i <= len; ++i)
	// {
	// 	std::cout << i << std::endl;
	// 	std::cout << std::string(s.end() - i, s.end()) << " ";
	// 	std::cout << std::string(t.begin(), t.begin() + i) << std::endl;
	// }

	std::string s("01267456789");
	std::string t("67");
	std::string r("***");
	
	int n(s.size());
	int m(t.size());

	for (int i(0); i + m < n; ++i)
	{
		if (std::string(s.begin() + i, s.begin() + i + m) == t)
		{
			std::string ss =  std::string(s.begin(), s.begin() + i) + r + std::string(s.begin() + i + m, s.end());
			std::cout << ss << std::endl;
		}
			// std::cout << std::string(s.begin() + i, s.begin() + i + m) << std::endl;
	}

	// Link(s, t);
	// std::cout << s << std::endl;

	return 0;
}

{
        //next初始化
    for(int i = 2 , j = 0 ; i <= n ; i ++)
    {
            while (j && a[i] != a[j + 1])
			{
				j = ne[j];
			}
            if( a[i] == a[j + 1] ) 
			j++;
            ne[i] = j;
    }


    //kmp匹配过程
    for(int i = 1 , j = 0 ; i <= m ; i ++ )
    {
        while( j && b[i] != a[j + 1] ) j = ne[j];
        if( b[i] == a[j + 1] ) 
			j++;
        if( j == n)//匹配成功
        {
           printf("%d ",i - n);
            j = ne[j];
        }
    }
}