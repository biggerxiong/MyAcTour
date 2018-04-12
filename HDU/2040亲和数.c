#include<stdio.h>
int main ()
{
	int a, b, sum1, sum2, i, k, m;
	scanf("%d", &m);
	for (k = 0; k < m; k ++)
	{
		printf("1\n");
		scanf("%d %d", &a, &b);
		printf("a=%d, b=%d\n2\n", a, b);
		for (i = 0, sum1 = 0; i < a / 2; i ++)
		{
			printf("a\n");
			if (a % i == 0)
			{
				sum1 += i;
				if (sum1 > b)
					break;
			} 
		}
		printf("3\n");
		for (i = 0, sum2 = 0; i < b / 2; i ++)
		{
			if (b % i == 0)
			{
				sum2 += i;
				if (sum2 > a)
					break;
			}
		}
		printf("4\n");
		if (sum2 == a && sum1 == b)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
