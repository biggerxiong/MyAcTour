#include<stdio.h>
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
int abs(int x) {
	if (x < 0)
		return -x;
	else
		return x;
}

int main() {
	long long fenzi = 0, fenmu = 1;
	long long a, b, numgcd;
	int n, i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld/%lld", &a, &b);
		if(!b)
			continue;
		
		fenzi *= b;
		a *= fenmu;
		fenmu *= b;
		fenzi += a;
		
		numgcd = gcd(fenzi, fenmu);
			
		fenzi /= numgcd;
		fenmu /= numgcd;
	}
	if (n)
		if (abs(fenzi) < fenmu && fenzi)
			printf("%lld/%lld", fenzi, fenmu);
		else {
			long long shang;
			shang = fenzi / fenmu;
			printf("%lld", shang);
			if (fenzi - shang * fenmu)
				printf(" %lld/%lld", fenzi - shang * fenmu, fenmu);
		}
	
	return 0;
}
