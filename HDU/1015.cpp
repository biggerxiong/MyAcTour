#include<iostream>
#include<cstring>
using namespace std;
//前两个数相加乘2 
//int a[21], n, book[41] = {0};
//__int64 ans;
//void dfs(int step) {
//	int i;
//	
//	if (step <= n) {
//		for (i = 1; i <= 3; i++) {
//			if (i == 2 && a[step - 1] == 2);
//			else {
//				a[step] = i;
//				dfs(step + 1);
//				a[step] = 0;
//			}
//		}
//	}
//	else 
//		ans++;
//}
//int main() {
//	int i;
//	
//	while (scanf("%d", &n) != EOF) {
//		for (i = 0; i <= n; i++) {
//			book[i] = 0;
//			a[i] = 0;
//		}
//		ans = 0;
//		dfs(1);
//		
//		cout << ans << endl;
//	}
//		
//	return 0;
//}


void LongAdd(char a[],char b[],int sum[], char ans[])
{
	int LenthA,LenthB,themax,LenthSum;
	LenthA=strlen(a);
	LenthB=strlen(b);
	
	if (LenthA>=LenthB)
	  themax=LenthA;
	else 
	  themax=LenthB;
	LenthSum=themax;
	
	int num1[10000]={0},num2[10000]={0},num3[10001]={0},i;
	for (i=LenthA-1;i>=0;i--)
	  num1[i]=a[LenthA-i-1]-'0';
	for (i=LenthB-1;i>=0;i--)
	  num2[i]=b[LenthB-i-1]-'0';
	  
	for (i=0;i<themax;i++)
	{
		num3[i]+=num1[i]+num2[i];
		if (num3[i]>9)
		{
			num3[i]=num3[i]%10;
			num3[i+1]+=1;
			if (i==themax-1)
			  LenthSum++;
		}
	}
	for (i=LenthSum-1;i>=0;i--)
//		printf("%d",num3[i]);
	  ans[LenthSum - 1 - i] = num3[i] + '0';
	ans[LenthSum] = '\0';
}

int main() {
	char ans[45][1000];
	char temp[1000];
	int i, sum[1000];
	strcpy(ans[1], "3\0");
	strcpy(ans[2], "8\0");
	
	for (i = 3; i <= 40; i++) {
		LongAdd(ans[i - 1], ans[i - 2], sum, ans[i]);
		LongAdd(ans[i], ans[i], sum, ans[i]);
	}
	
	while (scanf("%d", &i) != EOF) {
		cout << ans[i] << endl;
	}
	
	return 0;
} 
