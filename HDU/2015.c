#include<stdio.h>
int main()
{
	int n, m, i, a[105] = {0, 2}, sum, index;
	int  average = 0;
	
	while (scanf ("%d %d", &n, &m) != EOF)
	{
		sum = 0;
		i = 0;
		
		for (index = 1; index <= n; index ++)
		{
			if (i == m)
			{
				index --;
				average = sum / m;
				
				if (index == n)//判断是不是输出里的最后一个数 
					printf ("%d", average);
				else
					printf ("%d ", average);
					
				i = 0;
				sum = 0;
			}
			else 
			{
				if (a[index] == 0)
					a[index] = a[index - 1] + 2;
				
				sum += a[index];
				i ++;
			}
		}
		
		if (i != 0)
		{
			average = sum / i;
			printf("%d\n", average);
		}
		else 
			printf("\n");
	}
	
	return 0;
}
