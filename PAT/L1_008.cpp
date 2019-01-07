#include<stdio.h>
int main() {
	int a, b, sum = 0, i, time = 1;
	scanf("%d %d", &a, &b);
	
	for (i = a; i <= b; i++, time++){
		printf("%5d", i);
		sum += i;
		if (time % 5 == 0)
			printf("\n");
	}
	if ((b - a + 1) % 5 != 0)
		printf("\n");
	
	printf("Sum = %d", sum);
	return 0;
}
