#include <iostream>
#include <vector>

void Solve(void);

int main(void)
{
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
    int64_t n, m;
    std::cin >> n >> m;

    if (m < n / 2)
	{
		std::cout << -1 << std::endl;
		return;
	}

	std::vector<int64_t> anss(n);
	if (n % 2 == 0)
	{
		m -= n / 2;

		if (m % 2 == 1)
		{
			std::cout << -1 << std::endl;
			return;
		}

		// 3 4 3 4 3 2 3 2 3 2
		m /= 2;
		int64_t per(m / n * 2);
		int64_t extra(m % n);
		for (int i(0); i < n; i += 2)
		{
			anss[i] = 1 + per;
		}
		for (int i(1); i < n; i += 2)
		{
			anss[i] = per;
		}
		for (int i(0); i < std::min(extra, n / 2); ++i)
		{
			anss[1 + i*2] += 2;
		}
		extra -= n / 2;
		for (int i(0); i < extra; ++i)
		{
			anss[0 + i*2] += 2;
		}
	}
	else // n % 2 == 1
	{
		m -= n / 2;
		if (m % 2 == 1)
		{
			// 3 4 3 4 3 2 3 2 3
			// --m; 这句有没有都一样
			m /= 2;
			int64_t per(m / n * 2);
			int64_t extra(m % n);
			for (int i(0); i < n; i += 2)
			{
				anss[i] = 1 + per;
			}
			for (int i(1); i < n; i += 2)
			{
				anss[i] = per;
			}
			for (int i(0); i < std::min(extra, n / 2); ++i)
			{
				anss[1 + i * 2] += 2;
			}
			extra -= n / 2;
			for (int i(0); i < extra; ++i)
			{
				anss[0 + i * 2] += 2;
			}
		}
		else // m % 2 == 0
		{
			// 4 3 4 3 2 3 2 3 2
			m /= 2;
			int64_t per(m / n * 2);
			int64_t extra(m % n);
			for (int i(1); i < n; i += 2)
			{
				anss[i] = 1 + per;
			}
			for (int i(0); i < n; i += 2)
			{
				anss[i] = per;
			}
			for (int i(0); i < std::min(extra, n / 2); ++i)
			{
				anss[0 + i * 2] += 2;
			}
			extra -= n / 2;
			for (int i(0); i < extra; ++i)
			{
				anss[1 + i * 2] += 2;
			}
		}
	}

	for (int64_t ans : anss)
	{
		std::cout << ans << " ";
	}
	std::cout << std::endl;
}