#include <stdio.h>

int main() {
	int a[10], key = 0, i, num;

	for (i = 0; i < 10; i++)
		a[i] = 0;

	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}

	if (a[0] == 0)
		key = 1;

	for (i = 1; i < 10 && key == 0; i++) {
		if (a[i]) {
			printf("%d", i);
			a[i]--;
			key = 1;
		}
	}

	for (i = 0; i < 10; i++){
		while (a[i]--)
			printf("%d", i);
	}

	return 0;
}
