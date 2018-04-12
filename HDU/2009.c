#include<stdio.h>
#include<math.h>
int main()
{
    int n, m, i;
    float sum, last;
    while (scanf("%d %d", &n, &m) != EOF)
    {
    	sum = n;
    	last = sqrt(n);
    	for (i = 1; i < m; i ++)
    	{
    	    sum += last;
    	    last = sqrt(last);
    	}
    	printf("%.2f\n", sum);
    }
    return 0;
}
