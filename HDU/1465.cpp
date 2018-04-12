#include<iostream>
using namespace std;

//int a[21], n, book[21] = {0};
//long long ans;
//void dfs(int step) {
//	int i;
//	
//	if (step <= n) {
//		for (i = 1; i <= n; i++) {
//			if (!book[i] && i != step) {
//				book[i] = 1;
//				dfs(step + 1);
//				book[i] = 0;
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
//		ans = 0;
//		dfs(1);
//		
//		cout << ans << endl;
//	}
//		
//	return 0;
//}



int main() {
	long long a[25];
	int n, i;
	a[2] = 1;
	a[3] = 2;
	for (i = 4; i <= 20; i++) {
		a[i] = (a[i - 1] + a[i - 2]) * (i - 1);
	}
	
	while (scanf("%d", &n) != EOF) {
		cout << a[n] << endl;
	}
	
	return 0;
}
