#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int check(int []);
int jianfa(int [], int []);
int comp0(const void*a,const void*b)//0从小到大，1从大到小 
{
		return *(int*)a-*(int*)b;
}
int comp1(const void*a,const void*b)//0从小到大，1从大到小 
{
		return *(int*)b-*(int*)a;
}

int main() {
	srand(time(0));
	int num, a[4], b[4], ans[4], ans1; 
	int i, j;
	
	scanf("%d", &num);
	if (num % 1111 == 0)
		printf("%d - %d = 0\n\n", num, num);
	else {
		for (i = 0; i < 4; i++) {
			ans[i] = num % 10;
			num = num / 10;
		}
		
		while(check(ans) == 0) {
			for (i = 0; i < 4; i++)
				a[i] = b[i] = ans[i];
				
			qsort(a,4,sizeof(int),comp1);
			qsort(b,4,sizeof(int),comp0);
			
			for (i = 0; i < 4; i++)
				printf("%d", a[i]);
			printf(" - ");		
			for (i = 0; i < 4; i++)
				printf("%d", b[i]);
			printf(" = ");
			
			ans1 = jianfa(a, b);
			
			int n;
			for (i = 0,n = 1000; i < 4; i++) {
				ans[i] = ans1 / n;
				ans1 -= ans[i] * n;
				n = n / 10;
			}
		
		} 
	}
	printf("\n\n");
	return 0;
}

int check(int num[]) {
	int a[4] = {6,1,7,4};
	int i;
	
	for (i = 0; i < 4; i++)
		if (num[i] != a[i])
			break;
			
	if (i == 4)
		return 1;
	else 
		return 0;
}

int jianfa(int a[], int b[]) {
	int i, ans, num1 = 0, num2 = 0, n;
	

	for (i = 0, n = 1000; i < 4; i++, n /= 10)
		num1 += a[i] * n;
	for (i = 0, n = 1000; i < 4; i++, n /= 10)
		num2 += b[i] * n;
		
	ans = num1 - num2;
	printf("%d\n", ans);
	return ans;
}
