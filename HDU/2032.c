#include<stdio.h>
int main()
{
	int a[31][31], n, i, j;
	for (i = 0; i < 31; i ++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for (i = 2; i < 31; i ++)
		for (j = 1; j < i; j ++)
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i ++)
		{
			for (j = 0; j <= i - 1; j ++)
				printf("%d ", a[i][j]);
			printf("%d\n", a[i][j]);
		} 
		printf("\n");
	}
	return 0;
} 