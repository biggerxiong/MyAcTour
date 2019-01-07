#include <stdio.h>

int main () {
	int amax, bmax, am, bm;
	int a, b, c, d, n;

	scanf("%d %d %d", &amax, &bmax, &n);
	am = amax;
	bm = bmax;

	while (1) {
		scanf("%d %d %d %d", &a, &b, &c, &d);

		if (b == a + c && d != a + c)
			amax--;
		else if (d == a + c && b != a + c)
			bmax--;

		if (amax == -1 || bmax == -1)
			break;
	}

	if (amax == -1)
		printf("A\n%d", bm - bmax);
	else
		printf("B\n%d", am - amax);

	return 0;
}
