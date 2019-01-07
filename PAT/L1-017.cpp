#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char str[55];
	int i = 0, n = 0, len, k;
	float tax = 1.0, ans;

	cin >> str;
	k = len = strlen(str);

	if (str[0] == '-'){
		i = 1;
		tax += 0.5;
		k--;
	}

	if ((str[len - 1] - '0') % 2 == 0)
		tax *= 2;

	for (; i < len; i++) 
		if (str[i] == '2')
			n++;

	ans = n * 1.0 / k * tax;
	printf("%.2f%%\n", ans * 100);
	
	return 0;
}
