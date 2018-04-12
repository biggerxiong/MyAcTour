#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define inf 0x3f3f3f3f

int map[1003][1003], dis[1003], t, n;
bool book[1003];

void dij() {
	int i, j, minIndex, min;
	
	for (i = 1; i <= n; i++) 
		dis[i] = map[1][i];
	dis[1] = 0;
	book[1] = 0;
	
	for (j = 1; j < n; j++) {
		min = inf;
		for (i = 2; i <= n; i++) {
			if (book[i] && dis[i] < min) {
				minIndex = i;
				min = dis[i];
			}
		}
		book[minIndex] = 0;
		
		for (i = 1; i <= n; i++) {
			if (book[i] && map[minIndex][i] != inf)
				if (map[minIndex][i] + dis[minIndex] < dis[i])
					dis[i] = map[minIndex][i] + dis[minIndex];
		}
	}
	
}

int main () {
	cin >> t >> n;
	
	memset(map, 0x3f, sizeof(map));
	memset(book, 1, sizeof(book));
	
	int p1, p2, d;
	for (int i = 0; i < t; i++) {
		cin >> p1 >> p2 >> d;
		if (map[p1][p2] > d)
			map[p1][p2] = map[p2][p1] = d;
	}

	dij();
	cout << dis[n];

	return 0;
}
