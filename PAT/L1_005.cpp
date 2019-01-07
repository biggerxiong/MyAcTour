#include<stdio.h>
struct DATA {
	char num[15];
	int shiji, kaoshi;
}s[1005];

int main() {
	int n, i, a[1005], m, j;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%s %d %d", s[i].num, &s[i].shiji, &s[i].kaoshi);
	}
	
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (s[j].shiji == a[i])
				printf("%s %d\n", s[j].num, s[j].kaoshi);
		}
	}
	
	return 0;
}
