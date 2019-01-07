#include <stdio.h>

int d;
void print(long long num) {
	if (num < d)
		printf("%lld", num);
	else {
		print(num / d);
		printf("%lld", num % d);
	}
}
int main () {
	long long a, b;
	
	scanf("%lld %lld %d", &a, &b, &d);
	print(a + b);

	return 0;
}
