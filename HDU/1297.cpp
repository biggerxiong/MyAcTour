#include<iostream>
using namespace std;

int main() {
	int a[1005];
	int i, n;
	
	a[1] = 1;
	a[2] = 2;
	
	for (i = 3; i <= 1000; i++) {
		a[i] = a[i - 1] + i - 1;
	}
	
	while (scanf("%d", &n) != EOF) {
		cout << a[n] << endl;
	}
	
	return 0;
}
