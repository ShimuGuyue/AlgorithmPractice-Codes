#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	char a[9999];
	int i = 0;
	int flag = 0;
	int b[2000];
	scanf("%s", a);
	while (a[i] != '\n')
	{
		b[a[i]]++;
		if (b[a[i]] == n)
		{
			printf("%c", a[i]);
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0)
		printf("No");
	printf("%d", flag);
}