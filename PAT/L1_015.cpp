#include<stdio.h>
int main() {
	int n, i, j, len;
	char c;
	
	scanf("%d %c", &n, &c);
	len = (int )(n / 2.0 + 0.5);
	
	for (i = 0; i < len; i++){
		for (j = 0; j < n; j++)
			printf("%c", c);
		if (i != len - 1)
			printf("\n");
	}
	
	return 0;
}
