#include <iostream>
#include <vector>


const int64_t mod(1e9+7);
 
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int64_t> as(n);
    for (int64_t& a : as)
    {
        std::cin >> a;
    }

    int64_t increase(0);
    int64_t decrease(0);
 
    while(k--)
    {
        int op, x;
        std::cin >> op >> x;
        if(op == 1)
        {
            increase += x;
        }
        else // op == 2
        {
            if(x <= increase)
                increase -= x;
            else
            {
                decrease += x - increase;
                increase = 0;
            }
        }
    }
 
    int64_t ans(0);
    for(int64_t &a : as)
    {
        a -= decrease;
        if (a < 0)
            a = 0;
    }

    for(int64_t &a : as)
    {
        ans += a; ans %= mod;
    }

    ans += increase % mod * n; ans %= mod;
 
    std::cout << ans << std::endl;
}