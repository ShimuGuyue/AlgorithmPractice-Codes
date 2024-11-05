#include <iostream>
#include <vector>
#include <algorithm>

void Solve(void);

int main(void)
{
	int t(1);
	std::cin >> t;
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
	std::vector<int> nums(n);
	for (int& num : nums)
	{
		std::cin >> num;
	}
	std::sort(nums.begin(), nums.end());
	std::swap(nums.front(), nums.back());
	int64_t a(0);
	int64_t b(0);
	for (int i(0); i < n; ++i)
	{
		if (i % 2)
			a += nums[i];
		else
			b += nums[i];
	}
	if (a > b)
		std::cout << "kou" << std::endl;
	else if (a == b)
		std::cout << "draw" << std::endl;
	else if (a < b)
		std::cout << "yukari" << std::endl;
}