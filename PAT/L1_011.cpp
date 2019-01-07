#include<stdio.h>
int main() {
	int book[300] = {0};
	int i, num;
	char a[10001], b[10001], *p;
	
	gets(a);
	gets(b);
	
	for (p = b; *p != '\0'; p++) {
		num = *p;
		book[num] = 1;
//		printf("*num = %d\n", num);
	}
	
	for (p = a; *p != '\0'; p++) {
		num = *p;
//		printf("@num = %d\n", num);
		if (!book[num]) 
			printf("%c", *p);
	}
	
	return 0;
}
