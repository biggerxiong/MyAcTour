#include<Stdio.h>
int main()
{
	double a[51];
	int n;
	a[1] = 1;
	a[2] = 2;
	for (n = 3; n <= 50; n++)
		a[n] = a[n - 1] + a[n - 2];
	while (scanf("%d", &n) != EOF)
		printf("%.0lf\n", a[n]);
	return 0;
}
