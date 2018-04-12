#include <cstdio>
#include <iostream>
using namespace std;

void itoa(int, int *);
void clear(int *, int);

int main () {
	int a, b, c, s, i, temp, num[18], cal[18], lastTemp, book[70000];
		
	while (cin >> a && a) {
		cin >> b >> c >> s;
		
		clear(num, 16);
		clear(book, 65536);
		
		itoa(s, num);
		book[s] = 1;
		temp = (a * s + b) % c;
		lastTemp = s;

		while (temp != s) {
			clear(cal, 16);
			itoa(temp, cal);
			book[temp] = 1;
//			printf("%d\n", temp);
			
			for (i = 0; i < 16; i++) {
				if (num[i] != -1) {
					if (num[i] != cal[i])
						num[i] = -1;
				}
			}
			
			temp = (a * temp + b) % c;
			if (book[temp] == 1)
				break;
			
			if (temp == lastTemp)
				break;
			else
				lastTemp = temp;
				
//			for (i = 0; i < 16; i++)
//				printf("%d ", cal[i]);
//			printf("\n");
		}
		
		for (i = 15; i >= 0; i--)
			if (num[i] == 0)
				printf("0");
			else if (num[i] == 1)
				printf("1");
			else
				printf("?");
		printf("\n");
	}
	
	return 0;
}

void clear(int *arr, int n) {
	int i;
	for (i = 0; i < n; i++)
		arr[i] = 0;
}

void itoa(int a,int *num) {
	int i=0;
	while (a>0)
	{
		num[i++] += a % 2;
		a/=2;
	}
}
