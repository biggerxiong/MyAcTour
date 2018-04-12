#include<stdio.h> 
#include<math.h>
int main()
{
	int a[101], i, j, n, t;
	while (scanf ("%d", &n)!= EOF && n != 0)
	{
		for (i = 0; i < n; i ++)
			scanf ("%d",&a[i]) ;
		
		for (i = 0; i < n; i ++)
			for (j = i + 1; j < n; j ++)
			{
				if (abs(a[i]) < abs(a[j]))
				{
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
			
		for (i = 0; i < n - 1; i ++)
			printf("%d ", a[i]);
			
		printf("%d\n",a[i]);
	}
	return 0;
}
