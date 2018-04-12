#include<stdio.h>
float caculate(int, int, int, int, int, int);
int main()
{
	int length[100], width[100], i, j, k, n;
	float square;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		for (i = 0; i < n; i ++)
			scanf("%d %d", &length[i], &width[i]);
			
		square = 0;
		for (i = 0; i < n; i ++)
		{
			j = i + 1;
			k = j + 1;
			if (j > n)
				j -= n;
			if (k > n)
				k -= n;
			square += caculate(length[i], width[i], length[j], width[j], length[k], width[k]);
		}
					
		printf("%.1f\n", square);
	}
	return 0;
}
float caculate(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return (1.0 / 2)*(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
}
