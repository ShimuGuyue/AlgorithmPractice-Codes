#include <iostream>

int main(void)
{

    return 0;
}

bool Check(int x, int k)
{}

/* [l, mid - 1] + [mid, r] */
int Binary_Search(int l, int r, int k)
{
    while (l < r)
    {
        int mid((l + r + 1) / 2);
        if (Check(mid, k))
            l = mid;
        else
            r = mid - 1;   
    }
    return r; 
}

/* [l, mid] + [mid + 1, r] */
int Binary_Search(int l, int r, int k)
{
    while (l < r)
    {
        int mid((l + r) / 2);
        if (Check(mid, k))
            r = mid;
        else
            l = mid + 1;   
    }
    return l; 
}

int F(int x)
{}

/* 凸函数的极大值 */
int Ternary_Search(int l, int r)
{   
    while (l < r)
    {
        int l1((l * 2 + r * 1) / 3);
        int r1((l * 1 + r * 2) / 3);
        if (F(l1) > F(r1))
            r = r1 - 1;
        else if (F(l1 < F(r1)))
            l = l1 + 1;
        else 
            l = l1 + 1, r = r1 - 1; 
    }
    return std::max(F(l), F(r));
}

/* 凹函数的极小值 */
int Ternary_Search(int l, int r)
{   
    while (l < r)
    {
        int l1((l * 2 + r * 1) / 3);
        int r1((l * 1 + r * 2) / 3);
        if (F(l1) < F(r1))
            r = r1 - 1;
        else if (F(l1 > F(r1)))
            l = l1 + 1;
        else 
            l = l1 + 1, r = r1 - 1; 
    }
    return std::min(F(l), F(r));
}