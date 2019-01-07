#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int i, n, maxLen, m, j, len;
	int a[15], last = 2, temp, start, end;
	
	cin >> n;
	
	for (i = 0; i < 13; i++) {
		m = sqrt(n) + 1;
		
		for (j = last; j < m; j++) {
			if (n % j == 0) {
				a[i] = j;
				last = j;
				n = n / j;
				break;
			}
		}
		
		if (j == m) {
			len = i;
			break;
		}
	}
	
	cout << "*len = " << len << endl;
	for (i = 0; i < len; i++)
		cout << " " << a[i];
	
	start = 0; 
	end = 0;
	for (i = 0, maxLen = 0; i < len; i++) {
		temp = 1;
		for (j = i + 1; j < len; j++) {
			if (a[j - 1] == a[j]) {
				temp++;
			}
			else 
				break;
		}
		
		if (temp > maxLen) {
			maxLen = temp;
			start = i;
			end = j - 1;
		}
	}
	
	cout << endl << maxLen << endl << a[0];
	for (i = 1; i < maxLen; i++)
		cout << "*" << a[i];
		
	return 0;
}
