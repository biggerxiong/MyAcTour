#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main() {
	int n, u, d;
	int ans;
	srand(time(0));
	
//	n = rand() % 100;
//	u = rand() % 100;
//	d = rand() % u;
	cin >> n >> u >> d;
	while (n) {
		ans = 0;
		
		int temp;
		temp = (n - u) / (u - d);
		if ((n - u) % (u - d) != 0) 
			temp ++;
				
		ans = temp * 2 + 1;
		
		if (ans < 0)
			ans = 1;
			
//		cout << n << " " << u << " " << d << " " << ans << endl;
		cout << ans << endl;
		
		cin >> n >> u >> d;
//	n = rand() % 100;
//	u = rand() % 100;
//	d = rand() % u;
	}
	
	return 0;
} 
