#include <iostream>
#include <vector>

int main(void)
{
    int m, n;
    std::cin >> m >> n;

    std::vector<int> schedules(n * m); // 安排工作的顺序  
    std::vector<int> hadOrganizeds(n + 1, 1); // 各个工件当前要进行的工序序号
    std::vector<int> beginTime(n + 1, 1); // 各个元件当前要进行的工序的最早开始时间
    std::vector<std::vector<int>> machines(n + 1, std::vector<int>(m + 1)); // 每个工序的机器号
    std::vector<std::vector<int>> times(n + 1, std::vector<int>(m + 1)); // 每个工序的加工时间
    std::vector<std::vector<int>> flags(m + 1, std::vector<int>(n * m * 20)); //每个时间点各个机器的工作情况 0 1

    // 给定的安排顺序
    for (int i(0); i < n * m; ++i)
    {
        std::cin >> schedules[i];
    }
    // 每个工件的每个工序所使用的机器号
    for (int i(1); i <= n; ++i)
    {
        for (int j(1); j <= m; ++j)
        {
            std::cin >> machines[i][j];
        }
    }
    // 每个工件的每个工序的加工时间
    for (int i(1); i <= n; ++i)
    {
        for (int j(1); j <= m; ++j)
        {
            std::cin >> times[i][j];
        }
    }

    for (int work : schedules)
    {
        int index(hadOrganizeds[work]); // 将要执行的工序
        int begin(beginTime[work]); // 该工序最早开始的时间
        int time(times[work][index]); // 该工序要花费的时间 
        int loc(machines[work][index]); // 该工序要使用的机器
        std::vector<int>& vi(flags[loc]); // 该机器各时间点的工作情况

        for (int i(begin); i < vi.size(); ++i)
        {
            bool ok(true);
            for (int j(0); j < time; ++j)
            {
                if (vi[i + j])
                {
                    ok = false;
                    i += j;
                    break;
                }
            }
            if (ok)
            {
                beginTime[work] = i + time;
                for (int j(0); j < time; ++j)
                {
                    vi[i + j] = 1;
                }
                break;
            }
        }
        ++hadOrganizeds[work];
    }

    for (int i(flags.front().size() - 1); i > 0; --i)
    {
        for (int j(1); j <= m; ++j)
        {
            if (flags[j][i])
            {
                std::cout << i << std::endl;
                return 0;
            }
        }
    }
    
    return 0;
}