/*
    参考教程
    https://www.bilibili.com/video/BV1ifUkYVEBH/?spm_id_from=333.999.0.0&vd_source=fe9156abafd89942972a6860493f9a04
*/
#include <iostream>
#include <map>

void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif
	
	int t(1);
	//std::cin >> t;
	while (t--)
	{
		Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void Solve(void)
{
    int n;
    std::cin >> n;
    std::map<int, int> as;
    std::map<int, int> bs;
    for (int i(0); i < n; ++i)
    {
        int a;
        std::cin >> a;
        ++as[a];
    }
    for (int i(0); i < n; ++i)
    {
        int b;
        std::cin >> b;
        ++bs[b];
    }
    int len_a(0);
    int len_b(0);
    int both(0);
    for (std::pair<int, int> ii : as)
    {
        int i(ii.first);
        if (bs[i] == 0)
            ++len_a;
        else
            ++both;
    }
    for (std::pair<int, int> ii : bs)
    {
        int i(ii.first);
        if (as[i] == 0)
            ++len_b;
        // else
        //     ++both;
    }
    int ans;
    if (both <= abs(len_a - len_b))
        ans = n - (std::min(len_a, len_b) + both);
    else
    {
        both -= abs(len_a - len_b);
        ans = n - (std::max(len_a, len_b) + both / 2);
    }
    std::cout << ans << std::endl;
}