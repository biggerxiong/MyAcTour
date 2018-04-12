#include<iostream>
#include<cmath>
using namespace std;

int main() {
	double sum, k;
	int n, e;

	cin >> n;
	while (n) {
		sum = 1.0 * n * (n + 1) * (n + 2) / 6;
	
		e = (int )log10(sum);
		k = sum / pow(10, e);
		printf("%.2lfE%d\n", k, e);

		cin >> n;
	}

	return 0;
}
