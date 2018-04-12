#include <stdio.h>

int main () {
	long long m, n, a;

	scanf("%lld %lld %lld", &n, &m, &a);
//	int k = m / a, j = n / a;
//	
//	if (k * a < m)
//		k++;
//	if (j * a < n)
//		j++;
//
//	printf("%d", k * j);
	printf("%lld", ((m + a - 1) / a) * ((n + a - 1) / a));
	return 0;
}
