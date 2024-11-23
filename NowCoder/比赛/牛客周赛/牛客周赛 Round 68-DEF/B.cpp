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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> grid(n, std::vector<char>(m));
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < m; ++j)
        {
            std::cin >> grid[i][j];
        }
    }
    int x1, y1, x2, y2;
    int flag(0);
    for (int i1(0); i1 < n; ++i1)
    {
    for (int j1(0); j1 < m; ++j1)
    {
        for (int i2(i1); i2 < n; ++i2)
        {
        for (int j2(j1); j2 < m; ++j2)
        {
            bool find(true);
            for (int i3(i1); i3 <= i2; ++i3)
            {
            for (int j3(j1); j3 <= j2; ++j3)
            {
                if (grid[i3][j3] == '*')
                    find = false;
            }
            }
            if (!find)
                continue;
            int sum((i2 - i1 + 1) * (j2 - j1 + 1));
            if (sum > flag)
            {
                flag = sum;
                x1 = i1 + 1; y1 = j1 + 1;
                x2 = i2 + 1; y2 = j2 + 1;
            }
        }
        }
    }
    }
    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
}