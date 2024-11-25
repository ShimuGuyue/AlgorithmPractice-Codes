#include <stdio.h>
#include <string.h>
int main()
{
	char a[2000];
	int b[26] = {0};
	int i = 0;
	scanf("%s", a);
	for (int i(0); i < strlen(a); ++i)
	{
		int j(a[i] - 'a');
		b[j]++;
	}
	// while (scanf("%c", &a[i]) != '\n')
	// {
	// 	int j = a[i] - 'a';
	// 	b[j]++;
	// 	i++;
	// }
	for (int k = i - 1; k > 0; k--)
	{
		if (b[k] > b[k - 1])
		{
			int c = b[k];
			b[k] = b[k - 1];
			b[k - 1] = c;
		}
	}
	printf("%d", b[0]);
}