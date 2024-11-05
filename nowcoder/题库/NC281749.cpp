#include <iostream>
#include <vector>

namespace solve
{
	void Solve(void);
	int max(std::vector<int> vi, int x);
	int min(std::vector<int> vi, int x);
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
    int n, x;
	std::cin >> n >> x;
	std::vector<int> temperatures(n);
	for (int& temperature : temperatures)
	{
		std::cin >> temperature;
	}
	int max(solve::max(temperatures, x));
	int min(solve::min(temperatures, x));
	std::cout << max << " " << min << std::endl;
}

int solve::max(std::vector<int> vi, int x)
{
	if (vi.front() == -999)
		vi.front() = 50;
	if (vi.back() == -999)
		vi.back() = -50;
	for (int i(1); i < vi.size() - 1; ++i)
	{
		if (vi[i] != -999)
			continue;

		if (vi[i-1] - x >= -50)
			vi[i] = vi[i-1] - x;
		else
			vi[i] = 50;
	}

	int ans(0);
	for (int i(1); i < vi.size(); ++i)
	{
		if (vi[i-1] - vi[i] >= x)
			++ans;
	}
	return ans;
}

int solve::min(std::vector<int> vi, int x)
{
	if (vi.front() == -999)
		vi.front() = -50;
	if (vi.back() == -999)
		vi.back() = 50;

	for (int i(vi.size() - 1 - 1); i >= 1; --i)
	{
		if (vi[i] != -999)
			continue;
		
		if (vi[i+1] + x-1 <= 50)
			vi[i] = vi[i+1] + x-1;
		else
			vi[i] = 50;
	}
	
	int ans(0);
	for (int i(1); i < vi.size(); ++i)
	{
		if (vi[i-1] - vi[i] >= x)
			++ans;
	}
	return ans;
}