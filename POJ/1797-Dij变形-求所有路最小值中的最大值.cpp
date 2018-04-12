/*
 *creat at 2017-03-24 11:05:19
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f

int map[1003][1003], dis[1003], n, m;
bool book[1003];
void dij() {
	int i, j;
	memset(book, 1, sizeof(book));
	for (i = 1; i <= n; i++) 
		dis[i] = map[1][i];
	book[1] = 0;
	dis[1] = 0;

	int maxNum, maxIndex;
	for (i = 2; i < n; i++) {
		maxNum = dis[1];
		maxIndex = 1;
		for (j = 2; j < n; j++) {
			if (book[j] && maxNum <= dis[j]) {
				maxNum = dis[j];
				maxIndex = j;
			}
		}
		book[maxIndex] = 0;

		for (j = 2; j <= n; j++) {
			if (book[j]) {
				if (map[maxIndex][j] != 0) {
					if (dis[j] == 0)
						dis[j] = min(dis[maxIndex], map[maxIndex][j]);
					else
						dis[j] = max(dis[j], min(dis[maxIndex], map[maxIndex][j]));
				}
			}
		}
	}
}

int main () {
	int t, cases = 1;
	cin >> t;
	while (cases <= t) {
		cin >> n >> m;

		memset(map, 0, sizeof(map));
		int p1, p2, wei;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &p1, &p2, &wei);
			if (wei > map[p1][p2]) 
				map[p1][p2] = map[p2][p1] = wei;
		}

		dij();
		printf("Scenario #%d:\n", cases++);
		printf("%d\n\n", dis[n]);
	}

	return 0;
}