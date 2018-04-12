/*
 *creat at 2017-03-25 17:28:21
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f

int map[1003][1003], dis1[1003], dis2[1003], n, m, x;
bool book[1003];

void dij(int dis[]) {
	int i, j;
	memset(book, 1, sizeof(book));
	for (i = 1; i <= n; i++)
		dis[i] = map[x][i];
	dis[x] = 0;
	book[x] = 0;

	int minNum, minIndex;
	for (i = 1; i < n; i++) {
		minNum = inf;minIndex = 0;
		for (j = 1; j <= n; j++) {
			if (book[j] && minNum > dis[j]) {
				minNum = dis[j];
				minIndex = j;
			}
		}
		book[minIndex] = 0;

		for (j = 1; j <= n; j++) {
			if (book[j] && map[minIndex][j] != inf) 
				dis[j] = min(dis[j], map[minIndex][j] + dis[minIndex]);
		}
	}
}

void reverse() {
	int i, j, temp;
	for (i = 1; i <= n; i++) 
		for (j = 1; j <= i; j++) {
			temp = map[i][j];
			map[i][j] = map[j][i];
			map[j][i] = temp;
		}
}

int main () {
	cin >> n >> m >> x;
	int p1, p2, distance, i, j;

	memset(map, 0x3f, sizeof(map));
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &p1, &p2, &distance);
		if (distance < map[p1][p2])
			map[p1][p2] = distance;
	}

	dij(dis1);
	reverse();
	dij(dis2);

	for (i = 1; i <= n; i++)
		dis2[i] += dis1[i];
	int maxNum = 0;
	for (i = 1; i <= n; i++)
		if (dis2[i] < inf)
			maxNum = max(maxNum, dis2[i]);

	cout << maxNum << endl;
	return 0;
}