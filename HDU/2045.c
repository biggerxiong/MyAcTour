#include<stdio.h>
int main()
{
	double s[51];
	int n;
	s[1] = 3;
	s[2] = 6;
	s[3] = 6;
	for (n = 4; n < 51; n ++)
		s[n] = s[n - 1] + s[n - 2] * 2;
	while (scanf("%d", &n) != EOF)
		printf("%.0lf\n", s[n]);
		
	return 0;
}
