#include<stdio.h>
#include<string.h>

int main() {
	int ans[1000], a[1005], b;
	char str[1005], ch;
	int i, len, n = 0, last = 0, temp;
	
	scanf("%s", str);
	getchar();
	scanf("%c", &ch);
	
	len = strlen(str);
	b = ch - '0';
	for (i = 0; i < len; i++) 
		a[i] = str[i] - '0';

	if (a[0] >= b)
		i = 0;
	else {
		last = a[0];
		i = 1;
	}
		
	for (; i < len; i++){
		temp = last * 10 + a[i];
		ans[n++] = temp / b;
		last = temp % b;
	}
	
	for (i = 0; i < n; i++)
		printf("%d", ans[i]);
		
	if (ans[0] == 0)
		printf("0");

	printf(" %d", last);
	
	return 0;
}
