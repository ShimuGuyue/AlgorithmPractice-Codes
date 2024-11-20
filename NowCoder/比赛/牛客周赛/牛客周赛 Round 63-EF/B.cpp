#include <iostream>
#include <vector>

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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> as(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> as[i];
    }
    int ans(0);
    for (int l(0); l + k - 1 < n; ++l)
    {
        int r(l + k - 1);
        int sum_dif(0);
        for (int i(0); i < k / 2; ++i)
        {
            if (as[l + i] != as[r - i])
                ++sum_dif;
        }
        if (sum_dif == 1)
            ++ans;
    }
    std::cout << ans << std::endl;
}