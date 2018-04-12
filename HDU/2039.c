#include<Stdio.h>
int main()
{
	int m, i, k;
	double a, b, c;
	scanf("%d", &m);
	for (i = 0; i < m; i ++)
	{
		scanf("%lf %lf %lf", &a, &b, &c);
		k = 0;
		if (a == 0 || b == 0 || c == 0)
			printf("NO\n");
		else 
		{
			if ((a + b) > c && (a - b) < c)
				k ++;
			if ((b + c) > a && (b - c) < a)
				k ++;
			if ((a + c) > b && (a - c) < b)
				k ++;
			if (k == 3)
				printf("YES\n");
			else
				printf("NO\n");
			k = 0;
		}
	}
	return 0;
} 
