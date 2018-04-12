#include<stdio.h>
#include<math.h>
int main()
{
	int a[100][100], i, j, max;
	int m, n, imax, jmax;
	while (scanf ("%d %d", &m, &n) !=EOF)
	{
		max = 0;
		imax = 0;
		jmax = 0;
		for (i = 0; i < m; i ++)
			for (j = 0; j < n; j ++)
			{
				scanf ("%d", &a[i][j]);
				if (abs(a[i][j]) > max)
				{
					max = abs(a[i][j]);
					imax = i;
					jmax = j;
				}
			}
			
		printf("%d %d %d\n", imax + 1, jmax + 1, a[imax][jmax]);
		
	}
	return 0;
}
