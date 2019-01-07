#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int len;
int fun(char str[], int index) {
	int i, j, ans;
	
	for (i = index - 1, j = index + 1, ans = 0; i >= 0 && j < len; i--, j++, ans ++)
		if(str[i] != str[j])
			break;
			
	return 2 * ans + 1;
}
int main() {
	char str[1005];
	int i, ans, max = 0;
	
	gets(str);
	len = strlen(str);
	
	for (i = 0; i < len; i++) {
		ans = fun(str, i);
		if (max < ans)
			max = ans;
	}
	
	cout << max;
	
	return 0;
}
