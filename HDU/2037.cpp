#include<stdio.h>
#include<stdlib.h>
struct DATA{
	int s;
	int e;
};
typedef struct DATA data;
void sort(data [], int);
int main()
{
	data a[101];
	int i, j, n;
	while (scanf("%d", &n) != EOF)
	{
		if (0 == n)
			break;
		for (i = 0; i < n; i ++)
			scanf("%d %d", &a[i].s, &a[i].e);
		sort(a,n);
		int sum, last;
		last = a[0].e;
		sum = 1;
		for (i = 1; i < n; i ++)
		{
			if (a[i].s >= last)
			{
				sum ++;
				last = a[i].e;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
void sort(data a[], int n)
{
	data t;
	int i, j;
	for (i = 0; i < n; i ++)
		for (j = i + 1; j < n; j ++)
		{
			if (a[i].e > a[j].e)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
}
