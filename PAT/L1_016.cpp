#include<stdio.h>
#include<string.h>
int main() {
	int quan[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	int i, j, sum, num, key = 1, n;
	char str[20], m[18];
	
	scanf("%d", &n);
	strcpy(m,"10X98765432\0");
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		sum = 0;
		for (j = 0; j < 17; j++){
			num = str[j] - '0';
			sum += num * quan[j];
		}
//		printf("*quan = %d ,bi = %d,,,,%c,,,%c\n", sum, sum % 11, m[sum % 11], str[17]);
		
		if (str[17] != m[sum % 11]){
			printf("%s\n", str);
			key = 0;
		}
	}
	
	if (key)
		printf("All passed");
		
	return 0;
}
