#include<stdio.h>
#include<string.h>
int main()
{
	int n, i, j, len, sum;
	char str[1000];
	scanf("%d", &n);
	getchar(); 
	for (i = 0; i < n; i ++)
	{
		sum = 0;
		gets(str);
		len = strlen(str);
		for (j = 0; j < len; j ++)
			if (str[j] < 0)
				sum ++;
		printf("%d\n", sum / 2);
	}
	return 0;
}
