#include<stdio.h>
#include<string.h>

char str[100000], key[3] = {'P', 'A', 'T'};
int len, j, k, ans = 0;

void find(char ch, int i);

int main() {
	
	scanf("%s", str);
	
	len = strlen(str);

	find('P', 0);
	
	printf("%d", ans);
	
	return 0;	
}

void find(char ch, int i) {
	for (; i < len; i++) {
		if (ch == str[i]) {
			if (ch == 'P')
				find('A', i);
			else if (ch == 'A')
				find('T', i);
			else {
				ans++;
				ans = ans % 1000000007;
			}
		}
	}
}
