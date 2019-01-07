#include<iostream>
#include<cstdio>
using namespace std;

void quickSortxiaoda(int a[] ,int left,int right)
{
	if (left>right)
	  return; 

	int temp=a[left],j=right,i=left,t;
	while (i!=j)
	{
		for (;i<j&&a[j]>=temp;j--);

		for (;i<j&&a[i]<=temp;i++);

		if (i!=j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}		
	}
	t=a[i];
	a[i]=a[left];
	a[left]=t;

	quickSortxiaoda(a,left,i-1);
	quickSortxiaoda(a,i+1,right);
}

void quickSortdaxiao(int a[] ,int left,int right)
{
	if (left>right)
	  return; 

	int temp=a[left],j=right,i=left,t;
	while (i!=j)
	{
		for (;i<j&&a[j]<=temp;j--);

		for (;i<j&&a[i]>=temp;i++);

		if (i!=j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}		
	}
	t=a[i];
	a[i]=a[left];
	a[left]=t;

	quickSortdaxiao(a,left,i-1);
	quickSortdaxiao(a,i+1,right);
}

int main() {
	int num, i;
	int temp[5];
	int max, min;
	
	cin >> num;

	do {
		for (i = 3; i >= 0; i--) {
			temp[i] = num % 10;
			num /= 10;
		}
		
		quickSortdaxiao(temp, 0, 3);
		max = temp[0] * 1000 + temp[1] * 100 + temp[2] * 10 + temp[3];
		quickSortxiaoda(temp, 0, 3);
		min = temp[0] * 1000 + temp[1] * 100 + temp[2] * 10 + temp[3];
		
		num = max - min;
		printf("%04d - %04d = %04d", max, min, num);
		if (num == 0 || num == 6174)
			break;
		else 
			printf("\n");
	}while (num != 6174);
	
	return 0;
}

