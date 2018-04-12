#include<stdio.h>
int main()
{
	int a, b, temp, i;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		if (a == 0 && b == 0)
			break;
			
		temp = 1;
		for (i = 0; i < b; i ++)
		{
			temp *= a;
			temp %= 1000;
		}
		printf("%d\n", temp);
	}
}
