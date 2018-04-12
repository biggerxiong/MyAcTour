#include<stdio.h>
int main(){
	int f[1000],a,b,i,n;
	int len,key;
	a=999;
	b=266;
	f[1]=f[2]=1;
	
	for (i=3;i<1000;i++){
		f[i]=(a*f[i-1]+b*f[i-2])%7;
	}
	for (i=1;i<1000;i++)
		printf("%d ",f[i]);
	printf("\nn=%d",n);
	
	return 0;
}
