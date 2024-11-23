#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct People
{
    std::string name;
    std::string position;
    int help;
    int grade;
    int index;
};

bool cmp1(People a, People b);
bool cmp2(People a, People b);

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<People> peoples(n);
    for (int i(0); i < n; ++i)
    {
        std::cin >> peoples[i].name >> peoples[i].position >> peoples[i].help >> peoples[i].grade;
        peoples[i].index = i;
    }
    std::sort(peoples.begin() + 3, peoples.end(), cmp1);
    for (int i(0); i < n; ++i)
    {
        if (i < 1)
            peoples[i].position = "BangZhu";
        else if (i < 1 + 2)
            peoples[i].position = "FuBangZhu";
        else if (i < 1 + 2 + 2)
            peoples[i].position = "HuFa";
        else if (i < 1 + 2 + 2 + 4)
            peoples[i].position = "ZhangLao";
        else if (i < 1 + 2 + 2 + 4 + 7)
            peoples[i].position = "TangZhu";
        else if (i < 1 + 2 + 2 + 4 + 7 + 25)
            peoples[i].position = "JingYing";
        else
            peoples[i].position = "BangZhong";
    }
    std::sort(peoples.begin(), peoples.end(), cmp2);
    for (People pe : peoples)
    {
        std::cout << pe.name << " " << pe.position << " " << pe.grade << std::endl;
    }
    return 0;
}

bool cmp1(People a, People b)
{
    if (a.help != b.help)
        return a.help > b.help;
    return a.index < b.index;
}

bool cmp2(People a, People b)
{
    std::map<std::string, int> positions;
    positions["BangZhu"] = 1;
    positions["FuBangZhu"] = 2;
    positions["HuFa"] = 3;
    positions["ZhangLao"] = 4;
    positions["TangZhu"] = 5;
    positions["JingYing"] = 6;
    positions["BangZhong"] = 7;

    if (a.position != b.position)
        return positions[a.position] < positions[b.position];
    if (a.grade != b.grade)
        return a.grade > b.grade;
    return a.index < b.index;
}