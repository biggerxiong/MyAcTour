#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char str[1005][17];
	int i, j, n;
	int ans[1005], max;
	
	while(scanf("%d", &n) != EOF && n != 0) {
		max = 0;
		memset(ans, 0, 1005);
		
		for(i = 0; i < n; i++)
			scanf("%s", str[i]);
			
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++) {
				if (!strcmp(str[i], str[j]))
					ans[i]++;
			}
			
		max = 0;
		for (i = 1; i < n; i++) {
			if (ans[max] < ans[i])
				max = i;
		}
		
		printf("%s\n", str[max]);
	}
	
	return 0;
}
