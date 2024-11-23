#include <stdio.h>
int k;
int n;
void f(int n, int a[])
{
    int find = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == k)
                find = 1;
        }
    }
    if (find == 1)
        printf("yes");
    else
        printf("no");
}
int main()
{
    scanf("%d%d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    f(n, a);
    return 0;
}