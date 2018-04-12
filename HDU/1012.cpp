#include<iostream>
using namespace std;

int main () {
	cout << "n e" << endl;
	cout << "- -----------" << endl;
	
	int n, i, j;
	double ans;
	
	for (n = 0; n < 3; n++) {
		ans = 1;
		int last = 0;
		for (i = 1; i <= n; i++) {
			int sum = 1;
			for (j = 2; j <= i; j++) {
				sum *= j;
			}
			ans += 1.0 / sum;
		}
		
//		printf("%d %.9lf\n", n, ans);
		cout << n << " " << ans << endl;
	}

	for (n = 3; n < 10; n++) {
		ans = 1;
		int last = 0;
		for (i = 1; i <= n; i++) {
			int sum = 1;
			for (j = 2; j <= i; j++) {
				sum *= j;
			}
			ans += 1.0 / sum;
		}
		
		printf("%d %.9lf\n", n, ans);
//		cout << n << " " << ans << endl;
	}
	
	return 0;
}
