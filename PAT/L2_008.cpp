#include<stdio.h>
#include<string.h>
int len;
int fun(char str[], int index) {
	int i = index - 1, j = index + 1, time;
	for (time = 0; i >= 0 && j < len; time++, i--, j++) {
		if (str[i] != str[j])
			break;
	}
	return time * 2 + 1;
}
int main() {
	char str[1005];
	int i, max = 1, ans;
	
	gets(str);
	len = strlen(str);
	for (i = 1; i < len - 1; i++) {
		ans = fun(str, i);
		if (max < ans)
			max = ans;
	}
	printf("%d", max);
	
	return 0;
}
