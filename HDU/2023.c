#include<stdio.h>
struct DATA{
	int num[5];
	double stuAverage;
};
typedef struct DATA data;

int main()
{
	data a[50];
	int n, m, sum;
	int i, j;
	double numAverage[5];
	while (scanf("%d %d", &n, &m) != EOF)
	{
		sum = 0;
		for (i = 0; i < n; i ++)
		{
			for (j = 0; j < m; j ++)
			{
				scanf ("%d", &a[i].num[j]);
				sum += a[i].num[j];
			}
			a[i].stuAverage = 1.0 * sum / m;
			sum = 0;
		}
		
		sum = 0;
		for (j = 0; j < m; j ++)
		{
			for (i = 0; i < n; i ++)
				sum += a[i].num[j];
			numAverage[j] = 1.0 * sum / n;
			sum = 0;
		}
		
		for (i = 0; i < n - 1; i ++)
			printf("%.2lf ", a[i].stuAverage);
		printf("%.2lf\n", a[i].stuAverage);
		for (j = 0; j < m - 1; j ++)
			printf("%.2lf ", numAverage[j]);
		printf("%.2lf\n",numAverage[j]);
		
		sum = 0;//在这里sum指学生数量 
		for (i = 0; i < n; i ++)
		{
			
			for (j = 0; j < m; j ++)
			{
				if (a[i].num[j] < numAverage[j])
					break;
			}
			if (j == m)
				sum ++;
		}
		printf("%d\n\n", sum);
	}
	return 0;
}
