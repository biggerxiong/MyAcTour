#include<iostream>
using namespace std;

int main() {
	int cases, i, n, temp;
	
	cin >> cases;
	while (cases--) {
		cin >> n;
		i = 1;
		
		while (i < n) {
			n -= i;
			i++;
		}
		
		temp = n % 9;
		if (!temp)
			cout << "9" << endl;
		else
			cout << temp << endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//	int a[100005];
//	int head, tail, total, i, sum, temp, all;
//	int n;
//	
//	tail = 1;
//	all = 0;
//	
//	cin >> n;
//	for (total = 0; total < n; tail++) {
//		for (i = 1; i <= tail && total < n; i++) {
//			temp = i % 9;
//			if (temp == 0)
//				temp = 9;
////			a[total++] = temp;
//			total++;
//		}
////		if (tail == 10)
////			tail = 1;
//	}

//	for (i = 1; i < 10000000000; i++) {
//		sum = (i * (i + 1)) >> 1;
//		if (sum >= n)
//			break;
//	}
//	cout << "i = " << i - 1 << endl;
//	sum = (i * (i - 1)) >> 1;
//	temp = n - sum;
//	temp = temp % 9;
//	cout << "sum = " << sum << " temp = " << temp << endl;
//	if (temp == 0)
//		temp = 9;


//	cout << temp;
//	for (i = 1; i < 10; i++) {
//		cout << "*** " << i << endl;
//		sum = 0;
//		for (int j = 1; j < 1000; j++) {
//			if (a[j] == i){
//				printf("%d ", j);
//				sum++;
//			}
//		}
//		all += sum;
//		cout << endl << "sum = " << sum << endl << endl;
//	}
//	
//	cout << "all = " << all << endl;
	return 0;
}
