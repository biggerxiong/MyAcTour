#include <cstdio>
#include <iostream>
using namespace std;

bool map[105][105];
bool book[105][105];
int n, m, tmax = -1, sum = 0;

int check(int i, int j) {
	if (i <= 0 || j <= 0 || i > n || j > m)
		return 0;

	if (book[i][j] || !map[i][j])
		return 0;
	else {
		book[i][j] = true;
		return 1 + check(i - 1, j) + check(i + 1, j) + check(i, j - 1) + check(i, j + 1);
	}
}

int main () {
	int i, j, k, tempi, tempj;

	cin >> n >> m >> k;

	for (i = 1; i <= k; i++) {
		cin >> tempi >> tempj;
		map[tempi][tempj] = true;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			sum = check(i, j);
			if (sum > tmax)
				tmax = sum;
//			printf("sum = %d\n", sum);
		}
	}

//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= m; j++) {
//			cout << map[i][j] == false ? 0 : 1;
//		}
//		cout << endl;
//	}
	
	cout << tmax << endl;

	return 0;
}
