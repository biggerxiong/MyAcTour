#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int sum;
	int cases, i, len;
	char str[10005];
	
	cin >> cases;
	while (cases--) {
		cin >> str;
		sum = 1;
		
		len = strlen(str);
		for (i = 1; i <= len; i++) {
			if (str[i] == str[i - 1]) {
				sum++;
			}
			else {
				if (sum == 1)
					cout << str[i - 1];
				else 
					cout << sum << str[i - 1];
					
				sum = 1;
			}
		}
		cout << endl;
	}
	
	return 0;
}
