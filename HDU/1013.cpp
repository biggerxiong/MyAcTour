#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char str[1005];
	int num[1005], ans, len, i;
	
	cin >> str;
	while (str[0] != '0') {
		len = strlen(str);
		
		for (i = 0; i < len; i++)
			num[i] = str[i] - '0';
			
		ans = 0;
		for (i = 0; i < len; i++) {
			ans += num[i];
			if (ans > 9) {
				int t;
				t = ans / 10;
				ans = ans % 10;
				ans += t;
			}
		}
		
		cout << ans << endl;
		
		cin >> str;
	}
	return 0;
}
