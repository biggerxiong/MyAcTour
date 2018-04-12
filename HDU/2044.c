#include<Stdio.h>
double h[55];
int main()
{
	int i, n, a, b;
	h[1] = 1;
	h[2] = 2;
	for (i = 3; i < 50; i ++)
		h[i] = h[i - 1] + h[i - 2];
		
	scanf("%d", &n);
	for (i = 0; i < n; i ++)
	{
		scanf("%d %d", &a, &b);
		printf("%.0lf\n", h[b - a]);
	}
	return 0;
}
