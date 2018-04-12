#include<stdio.h>
void translate(int, int); 
int main()
{
	int n, r;//n为要转换的数，r为转换成多少进制 
	while (scanf("%d %d", &n, &r) != EOF)
	{
		if (n < 0)
		{
			putchar('-');
			n = -n;
		}
		translate(n, r);
		putchar('\n');
	}
	return 0;
} 
void translate(int n, int r)
{
	if (n < r)
	{
		if (n > 9)
			printf("%c", n + 55);
		else 
			printf("%d", n);
	}
	else 
	{
		translate(n / r, r);
		if (n % r > 9)
			printf("%c", n % r + 55);
		else 
			printf("%d", n % r);
	}
	
}
