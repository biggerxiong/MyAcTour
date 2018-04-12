#include<stdio.h> 
int main()
{
	int sum, n, i, a[105], last, b[6] = {100, 50, 10, 5, 2, 1}, j;
	
	while (scanf ("%d", &n) != EOF && n != 0)
	{
		sum = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%d", &a[i]);
			last = a[i];
			for (j = 0; j < 6; j++)
			{
				if (last != 0)
				{
					sum += last / b[j];
					last = last % b[j];
				}
				else 
					break;
			}
		}
			
		printf("%d\n", sum);
	}
	return 0;
}
