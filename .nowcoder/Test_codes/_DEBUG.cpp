
#ifdef ONLINEJUDGE
#include <iostream>
#include <fstream>

int main(void)
{
    std::ifstream fin("in.in");
    std::ofstream fout("out.out");

    int a, b;
    fin >> a >> b;
    fout << a + b << std::endl;
    return 0;
}

#endif