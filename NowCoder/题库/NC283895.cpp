#include <iostream>
#include <vector>

void Solve(void);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen(".in.in"  , "r", stdin );
	freopen(".out.out", "w", stdout);
	#endif

    // 关闭输入输出缓存，使效率提升
    std::ios::sync_with_stdio(false);
    // 解除cin和cout的默认绑定，来降低IO的负担使效率提升
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
	std::vector<int64_t> as(n);
	for (int i(0); i < n; ++i)
	{
		std::cin >> as[i];
	}

	std::vector<int64_t> sums(n);
	sums.front() = as.front();
	std::vector<int> positives(n);
	positives.front() = (as.front() > 0);
	for (int i(1); i < n; ++i)
	{
		sums[i] = as[i] + sums[i - 1];
		positives[i] = (as[i] > 0) + positives[i - 1];
	}

	if (sums.back() % 3)
	{
		std::cout << 0 << std::endl;
		return;
	}

	std::vector<int> sum1_indexs;
	std::vector<int> sum2_indexs;
	for (int i(0); i < n; ++i)
	{
		if (sums[i] == sums.back() / 3 * 1 && positives[i])
			sum1_indexs.push_back(i);
		if (sums[i] == sums.back() / 3 * 2)
			sum2_indexs.push_back(i);
	}

	int ans(0);
	for (int i(0); i < sum1_indexs.size(); ++i)
	{
		for (int j(0); j < sum2_indexs.size(); ++j)
		{
			int i1(sum1_indexs[i]);
			int i2(sum2_indexs[j]);
			if (i2 > i1 /*&& positives[i1]*/ && positives[i2] - positives[i1] && positives.back() - positives[i2])
				++ans;
		}
	}
	std::cout << ans << std::endl;
}