#include<stdio.h>
int main()
{
	long long int a[40];
	int i;
	a[1] = 3;
	a[2] = 8;
	for (i = 3; i < 40; i ++)
		a[i] = (a[i - 1] + a[i - 2]) * 2;
	while (scanf("%d", &i) != EOF)
		printf("%lld\n", a[i]);
	return 0;
}
