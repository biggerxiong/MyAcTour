#include<stdio.h>
#include<string.h>
void LongAdd(char [],char []);
int main()
{
	int cases,n,i,lentha,lenthb;
	
	scanf("%d",&cases);
	getchar();
	for (n=1;n<=cases;n++)
	{
		lentha=0;
		lenthb=0;
		char a[10000],b[10000],ch;

		scanf("%s",&a);
		scanf("%s",&b);
		getchar();
		
		printf("Case %d:\n",n);
		printf("%s + %s = ",a,b);
		LongAdd(a,b);
		if (n!=cases)
		printf("\n\n");
		else
		printf("\n");
	}
	return 0;
}
void LongAdd(char a[],char b[])
{
	int LenthA,LenthB,themax,sum[10000]={0},LenthSum;
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
	
	for (i=0;i<LenthSum;i++)
	  sum[i]=num3[LenthSum-i-1];
	for (i=0;i<LenthSum;i++)
	  printf("%d",sum[i]);
}