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
    int n, t;
    std::cin >> n >> t;
    std::vector<int> as(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> as[i];
    }
    int ans(0);
    int sum_time(0);
    int sum_count(0);
    int i(0), j(0);
    while (j < n)
    {
        if (sum_time + as[j] <= t)
        {
            ++sum_count;
            sum_time += as[j];
            ++j;
        }
        else
        {
            --sum_count;
            sum_time -= as[i];
            ++i;
        }
        ans = std::max(ans, sum_count);
    }
    std::cout << ans << std::endl;
}