#include <iostream>
#include <iomanip>
#include <vector>

namespace solve
{
	void Solve(void);
}

int main(void)
{
	int t(1);
	//std::cin >> t;
	while (t--)
	{
		solve::Solve();
		//std::cout << std::endl;
	}
	return 0;
}

void solve::Solve(void)
{
    int n, m;
	std::cin >> n >> m;
	std::vector<long double> as(n+1);
	std::vector<long double> sums(n+1);
	std::vector<int> ls(n+1);
	std::vector<int> rs(n+1);
	for (int i(1); i <= n; ++i)
	{
		std::cin >> as[i];
		sums[i] = sums[i-1] + as[i];
	}
	for (int i(1); i <= n; ++i)
	{
		ls[i] = i;
		rs[i] = i;
	}

	while (m--)
	{
		int op;
		std::cin >> op;
		if (op == 1)
		{
			int l, r;
			std::cin >> l >> r;
			l = std::min(l, ls[l]);
			r = std::max(r, rs[r]);
			for (int i(l); i <= r; ++i)
			{
				if (rs[i] == r)
					break;
				rs[i] = r;
			}
			for (int i(r); i >= l; --i)
			{
				if (ls[i] == l)
					break;
				ls[i] = l;
			}
		}
		else // op == 2
		{
			int i;
			std::cin >> i;
			int l(ls[i]);
			int r(rs[i]);
			long double sum(sums[r] - sums[l-1]);
			long double ave(sum / (r - l + 1));
			std::cout << std::fixed << std::setprecision(10) << ave << std::endl;
		}
	}
}