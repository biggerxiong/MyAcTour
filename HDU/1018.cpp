#include<stdio.h>

int main() {
	long ying[2] = {0}, ping[2] = {0}, shu[2] = {0}; //0 for jia, 1 for yi
	long a[2][3] = {0}; //Ë³Ðò B C J
	long i, j, n, max;
	char jia, yi;
	
	scanf("%ld", &n);
	getchar();
	for (i = 0; i < n; i++){
		scanf("%c %c", &jia, &yi);
		getchar();
		
		if (jia == 'J' && yi == 'C') {
			ying[1]++;
			a[1][1]++;
		}
		else if (jia == 'J' && yi == 'B') {
			ying[0]++;
			a[0][2]++;
		}
		else if (jia == 'C' && yi == 'J') {
			ying[0]++;
			a[0][1]++;
		}
		else if (jia == 'C' && yi == 'B') {
			ying[1]++;
			a[1][0]++;
		}
		else if (jia == 'B' && yi == 'C') {
			ying[0]++;
			a[0][0]++;
		}
		else if (jia == 'B' && yi == 'j') {
			ying[1]++;
			a[1][2]++;
		} 
	}
	 
	printf("%ld %ld %ld\n", ying[0], n - ying[1] - ying[0], ying[1]);
	printf("%ld %ld %ld\n", ying[1], n - ying[1] - ying[0], ying[0]);
	 
	max = ying[0];
	for (j = 0; j < 2; j++) {
	 	max = 0;
	 	for (i = 1; i < 3; i++) {
	 		if (a[j][max] < a[j][i]) 
	 			max = i;
		}
		
		switch(max) {
			case 0:
				printf("B");
				break;
			case 1:
				printf("C");
				break;
			case 2:
				printf("J");
				break;
		}
		
		if (j == 0)
			printf(" ");
	}
	
	return 0;
}
