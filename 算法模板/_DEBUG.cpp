#include <iostream>

int main(void)
{

    return 0;
}

bool Check_Turn_Right(int x, int k)
{}
int Binary_Search(int l, int r, int k)
{
    while (l <= r)
    {
        int mid((l + r) / 2);
        if (Check_Turn_Right(mid, k))
            l = mid + 1;
        else
            r = mid;   
    }
    return (l + r) / 2; 
}

bool Check_Turn_Left(int x, int k)
{}
int Binary_Search(int l, int r, int k)
{
    while (l <= r)
    {
        int mid((l + r) / 2);
        if (Check_Turn_Left(mid, k))
            l = mid;
        else
            r = mid - 1;   
    }
    return (l + r) / 2; 
}