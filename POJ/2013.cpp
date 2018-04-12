#include <stdio.h>

int main() {
	int n, i, cases = 1;
	char str[16][27];

	while (scanf("%d", &n) != EOF && n) {
		getchar();
		
		for (i = 0; i < n; i++) 
			gets(str[i]);

		printf("SET %d\n", cases++);
		
		for (i = 0; i < n; i += 2) 
			printf("%s\n", str[i]);
		for (i = n % 2 == 1 ? n - 2 : n - 1; i >= 0; i -= 2)
			printf("%s\n", str[i]);
	}

	return 0;
}
