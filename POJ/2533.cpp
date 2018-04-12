#include <stdio.h>

#define maxn 1005

int a[maxn], dp[maxn];

int main () {
	int n, i, j;
//	memset(dp, 0, sizeof(dp));
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	int len = 1;
	dp[len] = a[0];

	for (i = 1; i < n; i++) {
		if (dp[len] < a[i])
			dp[++len] = a[i];
		else
			for (j = len - 1; j >= 0; j--) {
				if (dp[j] < a[i]) {
					dp[j + 1] = a[i];
					break;
				}
			}
	}

//	for (i = 1; i <= len; i++)
//		printf("%d ", dp[i]);
		
	printf("%d", len);

	return 0;
}
