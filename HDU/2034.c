#include<stdio.h> 
int main()
{
	int a[105], b[105], m, n, i, j, k;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		
		for (i = 0; i < n; i ++)
			scanf("%d", &a[i]);
		for (i = 0; i < m; i ++)
			scanf("%d", &b[i]);
		for (i = 0; i < n; i ++)
			for (j = i + 1; j < n; j ++)
			{
				if (a[i] > a [j])
				{
					k = a[i];
					a[i] = a[j];
					a[j] = k;
				}
			}
			
		k = 0;
		if (m != 0)
		{
			for (i = 0; i < n; i ++)
			{
				for (j = 0; j < m; j ++)
				{
					if (a[i] == b[j])
						break;
				}
				if (j == m)
				{
					printf("%d ", a[i]);
					k ++;
				}
			}
			if (k == 0)
				printf("NULL");
			printf("\n");
		}
		else
		{
			for (i = 0; i < n; i ++)
				printf("%d ", a[i]);
			printf("\n");
		}
	}
	return 0;
}
