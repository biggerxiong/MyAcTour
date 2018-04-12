#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int cases;
	long num, ans;
	
	cin >> cases;
	while (cases--) {
		cin >> num;
		long double a;
		
		a = num * log10 (num);
		a -= (long long) a;
		ans = pow(10, a);
		
		cout << ans << endl;
	}
	
	return 0;
}
