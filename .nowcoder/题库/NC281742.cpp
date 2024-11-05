#include <iostream>
#include <vector>

int k;
std::string flag;

std::vector<std::string> drugs;

void Dfs(int index, std::string patient, int sum, int &ans);
void Solve(void);

int main(void)
{
	int t(1);
	// std::cin >> t;
	while (t--)
	{
		Solve();
		// std::cout << std::endl;
	}
	return 0;
}

void Solve(void)
{
	int n, m;
	std::cin >> n >> m;
	flag = std::string(m, '0');
	std::vector<std::string> patients(n);
	for (std::string &patient : patients)
	{
		std::cin >> patient;
	}
	std::cin >> k;
	drugs.resize(k);
	for (std::string &drug : drugs)
	{
		std::cin >> drug;
	}

	for (int i(0); i < n; ++i)
	{
		int ans(k + 1);
		Dfs(0, patients[i], 0, ans);
		if (ans == k + 1)
			ans = -1;
		std::cout << ans << std::endl;
	}
}

void Dfs(int index, std::string patient, int sum, int &ans)
{
	if (patient == flag)
	{
		ans = std::min(ans, sum);
		return;
	}

	if (index == k)
		return;

	Dfs(index + 1, patient, sum, ans);
	for (int i(0); i < patient.size(); ++i)
	{
		if (drugs[index][i] == '1')
			patient[i] = '0';
	}
	Dfs(index + 1, patient, sum + 1, ans);
}