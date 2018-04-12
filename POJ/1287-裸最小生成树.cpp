/*
 *creat at 2017-05-27 12:13:25
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornr(i, n) for(int i = n - 1; i >= 0; i--)

#define MAXN 10000

typedef struct NODE {
	int x, y, value;
}Node;

int f[MAXN], map[55][111];
Node g[111];

//并查集的知识，获取n节点的祖先
int getf(int n) {
	if (f[n] == n)
		return n;
	else {
		return f[n] = getf(f[n]);
	}
}

//判断两个节点的祖先是否相同，若相同则代表有环
int merge(int x, int y) {
	int rootx = getf(x), rooty = getf(y);
	if (rootx != rooty) {
		f[rooty] = rootx;
		return 1;
	}
	return 0;
}

bool cmp(Node a, Node b) {
	return a.value < b.value;
}

int main () {
	int point, edges;
	int tempx, tempy, templen;

	while (scanf("%d", &point) && point) {
		scanf("%d", &edges);

		forn(i, point+1) f[i] = i;
		memset(map, 0x3f3f, sizeof(map));

		forn(i, edges) {
			scanf("%d %d %d", &tempx, &tempy, &templen);
			map[tempx][tempy] = min(map[tempx][tempy], templen);
		} 

		int index = 0;
		forn(i, point+1) 
			forn(j, point+1) {
				if (map[i][j] != inf) {
					g[index].x = i;
					g[index].y = j;
					g[index++].value = map[i][j];
				}
			}
		sort(g, g+index, cmp);

		// forn(i, point)
		// 	printf("%d %d %d\n", g[i].x, g[i].y, g[i].value);

		int sum = 0, curedge = 0, curindex = 0;
		while (curedge != point - 1) {
			if (merge(g[curindex].x, g[curindex].y)) {
				sum += g[curindex].value;
				curedge++;
			}
			curindex ++;
		}
		printf("%d\n", sum);
	}

	return 0;
}