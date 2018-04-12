#include<stdio.h>
struct time{
	int hour, minute, second;
};
int main()
{
	struct time a, b, sum;
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i ++)
	{
		scanf("%d %d %d", &a.hour, &a.minute, &a.second);
		scanf("%d %d %d", &b.hour, &b.minute, &b.second);
		sum.hour = a.hour + b.hour;
		sum.minute = a.minute + b.minute;
		sum.second = a.second + b.second;
		if (sum.second >= 60)
		{
			sum.minute ++;
			sum.second -= 60;
		}
		if (sum.minute >= 60)
		{
			sum.hour ++;
			sum.minute -= 60;
		}
		printf("%d %d %d\n", sum.hour, sum.minute, sum.second);
	}
	return 0;
} 
