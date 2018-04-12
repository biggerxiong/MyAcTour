#include<stdio.h>
int a[50];
void fun(void );
int main()
{
	int m, n, i;
	fun();
	scanf("%d", &n);
	for (i = 0; i < n; i ++)
	{
		scanf("%d", &m);
		printf("%d\n", a[m - 1]);
	}
	return 0;
}
void fun(void)
{
	int i;
	a[1] = 1;
	a[2] = 2;
	for ( i = 3; i < 41; i ++)
		a[i] = a[i - 1] + a[i - 2];
}
