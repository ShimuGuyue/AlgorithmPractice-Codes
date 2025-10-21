#include <iostream>
#include <vector>

void Solve(void);

int main(void)
{
	#ifdef Shimu_Guyue
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

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
    std::vector<std::vector<char>> grid(n, std::vector<char>(n));
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < n; ++j)
        {
            std::cin >> grid[i][j];
        }
    }
    char flag[7]{'y', 'i', 'z', 'h', 'o', 'n', 'g'};
    std::vector<std::vector<char>> no_stars(n, std::vector<char>(n));
    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < n; ++j)
        {
            if (grid[i][j] != 'y')
                continue;
            if (i + 6 < n)
            {
                bool ok(true);
                for (int k(1); k < 7; ++k)
                {
                    if (grid[i + k][j] != flag[k])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for (int k(0); k < 7; ++k)
                    {
                        no_stars[i + k][j] = '*';
                    }
                }
            }
            if (j + 6 < n)
            {
                bool ok(true);
                for (int k(1); k < 7; ++k)
                {
                    if (grid[i][j + k] != flag[k])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for (int k(0); k < 7; ++k)
                    {
                        no_stars[i][j + k] = '*';
                    }
                }
            }
            if (i - 6 >= 0)
            {
                bool ok(true);
                for (int k(1); k < 7; ++k)
                {
                    if (grid[i - k][j] != flag[k])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for (int k(0); k < 7; ++k)
                    {
                        no_stars[i - k][j] = '*';
                    }
                }
            }
            if (j - 6 >= 0)
            {
                bool ok(true);
                for (int k(1); k < 7; ++k)
                {
                    if (grid[i][j - k] != flag[k])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for (int k(0); k < 7; ++k)
                    {
                        no_stars[i][j - k] = '*';
                    }
                }
            }
            if (i + 6 < n && j + 6 < n)
            {
                bool ok(true);
                for (int k(1); k < 7; ++k)
                {
                    if (grid[i + k][j + k] != flag[k])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for (int k(0); k < 7; ++k)
                    {
                        no_stars[i + k][j + k] = '*';
                    }
                }
            }
            if (i + 6 < n && j - 6 >= 0)
            {
                bool ok(true);
                for (int k(1); k < 7; ++k)
                {
                    if (grid[i + k][j - k] != flag[k])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for (int k(0); k < 7; ++k)
                    {
                        no_stars[i + k][j - k] = '*';
                    }
                }
            }
            if (i - 6 >= 0 && j + 6 < n)
            {
                bool ok(true);
                for (int k(1); k < 7; ++k)
                {
                    if (grid[i - k][j + k] != flag[k])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for (int k(0); k < 7; ++k)
                    {
                        no_stars[i - k][j + k] = '*';
                    }
                }
            }
            if (i - 6 >= 0 && j - 6 >= 0)
            {
                bool ok(true);
                for (int k(1); k < 7; ++k)
                {
                    if (grid[i - k][j - k] != flag[k])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for (int k(0); k < 7; ++k)
                    {
                        no_stars[i - k][j - k] = '*';
                    }
                }
            }
        }
    }

    for (int i(0); i < n; ++i)
    {
        for (int j(0); j < n; ++j)
        {
            if (no_stars[i][j] == '*')
                std::cout << grid[i][j];
            else
                std::cout << "*";
        }
        std::cout << std::endl;
    }
}