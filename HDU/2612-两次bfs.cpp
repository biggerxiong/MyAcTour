#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define inf 50000
using namespace std;

typedef struct Node {
	int x, y, step;
}NODE;

char map[205][205];
bool book[205][205];
int n, m, time[205][205], mx, my, ans, yx, yy;
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

bool check(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	else if (map[x][y] == '#') {
		return false;
	}
	
	if (book[x][y]) {
		book[x][y] = false;
		return true;
	}
	
	return false;
}

void bfsM() {
	queue <NODE> que;
	NODE node, newNode;

	node.x = mx;
	node.y = my;
	node.step = 0;
	que.push(node);

	while (!que.empty()) {
//		cout << que.size() << endl;
		node = que.front();
		if (map[node.x][node.y] == '@') {
//			printf("m find at %d %d  step:%d\n", node.x, node.y, node.step);
			time[node.x][node.y] = node.step;
		}

		for (int i = 0; i < 4; i++) {
			newNode.x = node.x + dir[i][0];
			newNode.y = node.y + dir[i][1];

			if (check(newNode.x, newNode.y)) {
				newNode.step = node.step + 1;
				que.push(newNode);
			}
		}
		
		que.pop();
	}
}

void bfsY() {
	queue <NODE> que;
	NODE node, newNode;

	node.x = yx;
	node.y = yy;
	node.step = 0;
	que.push(node);

	while (!que.empty()) {
		node = que.front();
		if (map[node.x][node.y] == '@') {
//			printf("y find at %d %d  step:%d\n", node.x, node.y, node.step);
			if (time[node.x][node.y] != 0) {
				ans = time[node.x][node.y] + node.step < ans ? time[node.x][node.y] + node.step : ans;
			}
		}

		for (int i = 0; i < 4; i++) {
			newNode.x = node.x + dir[i][0];
			newNode.y = node.y + dir[i][1];
			if (check(newNode.x, newNode.y)) {
				newNode.step = node.step + 1;
				que.push(newNode);
			}
		}
		
		que.pop();
	}
}

int main () {
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'Y') {
					yx = i;
					yy = j;
				}
				else if (map[i][j] == 'M') {
					mx = i;
					my = j;
				}
			}
			getchar();
		}
		
		
		memset(time, 0, sizeof (time));
		memset(book, 1, sizeof (book));
		ans = inf;

		bfsM();
		memset(book, 1, sizeof (book));
		bfsY();

//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) 
//				cout << book[i][j];
//			cout << endl;
//		}
		cout << ans * 11 << endl;
	}
	return 0;
}
