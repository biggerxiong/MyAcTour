#include<stdio.h>
int jiechen(int n) {
	int i, s = 1;
	for (i = 1; i <= n; i++) {
		s *= i;
	}
	
	return s;
}
int main() {
	int s = 1, n, i;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		s += jiechen(i);
	}
	printf("%d", s);
	
	return 0;
}
