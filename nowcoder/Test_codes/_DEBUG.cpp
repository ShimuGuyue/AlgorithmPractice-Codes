#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = N - 1; i >= 1; i--)
    {
        if (i <= 2)
        {
            printf("%d", i);
            break;
        }
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
            if (j == i - 1)
            {
                printf("%d ", i);
            }
        }
    }
    return 0;
}
