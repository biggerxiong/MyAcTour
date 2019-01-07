#include<stdio.h>
#include<string.h>
int bijiao(char *a, char *b) {
	int lena, lenb;
	
	if (*a == '-' && *b != '-')
		return 1;
	else if (*b == '-' && *a != '-')
		return 0;
	else if (*a != '-' && *b != '-') {
		lena = strlen(a);
		lenb = strlen(b);
	
		if (lena < lenb) 
			return 1;
		else if (lena > lenb)
			return 0;
		else {
			if (strcmp(a, b) < 0)
				return 1;
			else 
				return 0;
		}
	}
	else {
		lena = strlen(a);
		lenb = strlen(b);
	
		if (lena < lenb) 
			return 0;
		else if (lena > lenb)
			return 1;
		else {
			if (strcmp(a, b) < 0)
				return 0;
			else 
				return 1;
		}
	}
	
}
int main() {
	char str[3][10001];
	int a[3], little, big, i;
	
	for (i = 0; i < 3; i++)
		scanf("%s", str[i]);
	
	if (bijiao(str[0], str[1])) {
		a[0] = 1;
		a[1] = 0;
	}
	else {
		a[1] = 1;
		a[0] = 0;
	}
	
	if (bijiao(str[a[0]], str[2])) {
		a[2] = a[1];
		a[1] = a[0];
		a[0] = 2;
	}
	else {
		if (bijiao(str[a[1]], str[2])) {
			a[2] = a[1];
			a[1] = 2;
		}
		else 
			a[2] = 2;
	}
	
	printf("%s->%s->%s", str[a[2]], str[a[1]], str[a[0]]);
		
	return 0;
}
