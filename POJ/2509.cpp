#include <stdio.h>

int main() {
	int n, k, ans;

	while (scanf("%d %d", &n, &k) != EOF) {
		ans = n;
		while(n >= k) {
			int temp = n / k;
			ans += temp;
			n %= k;
			n += temp;
		}

		printf("%d\n", ans);
	}

	return 0;
}
