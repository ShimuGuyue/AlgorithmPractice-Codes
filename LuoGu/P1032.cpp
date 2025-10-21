/**
 * 	https://www.bilibili.com/video/BV1EG4y167Ht/
 */
#include <iostream>
#include <vector>
#include <queue>

struct BfsData
{
	std::string s;
	int count;
};


std::string a, b;
std::vector<std::pair<std::string, std::string>> rules;
int n;

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
	// std::string a, b;
	std::cin >> a >> b;
	// std::vector<std::pair<std::string, std::string>> rules;
	std::string turn1, turn2;
	while (std::cin >> turn1 >> turn2)
	{
		rules.push_back({turn1, turn2});
	}
	n = rules.size();

	std::queue<BfsData> bfs;
	bfs.push({a, 0});
	while (!bfs.empty())
	{
		BfsData data(bfs.front());
		bfs.pop();

		if (data.count == 10)
			continue;
		for (int i(0); i < n; ++i)
		{
			int k(data.s.find(rules[i].first));
			while (k != std::string::npos)
			{
				std::string temp(data.s);
				temp.replace(k, rules[i].first.size(), rules[i].second);
				if (temp == b)
				{
					std::cout << data.count + 1 << std::endl;
					return;
				}
				bfs.push({temp, data.count + 1});
				k = data.s.find(rules[i].first, k + 1);
			}
		}
	}
	std::cout << "NO ANSWER!" << std::endl;
}