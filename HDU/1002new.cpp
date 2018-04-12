#include<stdio.h>
#include<string.h>
void LongAdd(char [],char [],int [],int);
int main()
{
	char a[10000],b[10000];
	int sum[10000],LenthSum;
	scanf("%s",&a);
	scanf("%s",&b);
	LongAdd(a,b,sum,LenthSum);
}
void LongAdd(char a[],char b[],int sum[],int LenthSum)
{
	int LenthA,LenthB,themax;
	LenthA=strlen(a);
	LenthB=strlen(b);
	if (LenthA>=LenthB)
	  themax=LenthA;
	else 
	  themax=LenthB;
	LenthSum=themax;
	
	int num1[10000],num2[10000],num3[10001],i;
	for (i=LenthA-1;i>=0;i--)
	  num1[i]=a[LenthA-i-1]-'0';
	for (i=LenthA-1;i>=0;i--)
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