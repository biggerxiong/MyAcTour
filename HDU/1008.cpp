#include<iostream>
using namespace std;

int main() {
	int last, ans, n, i, floor;
	
	while (cin >> n && n){
		last = 0;
		ans = 0;
		int temp;
		
		for (i = 0; i < n; i++) {
			cin >> floor;
			temp = floor - last;
			
			if (temp < 0) {
				ans += -4 * temp + 5;
			}
			else {
				ans += 6 * temp + 5;
			}
//			printf("*floor = %d, temp = %d, ans = %d\n", floor, temp, ans);
			last = floor;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
