#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int pl, pr, pc;
	int step;
};

void bfs();
bool check(int, int, int);
int l, r, c, map[33][33][33], book[33][33][33]; 
int startl, startr, startc, endL, endr, endc, ans;
int dir[6][3] = {0, 0, 1, 0, 0, -1, 0, 1, 0, 0, -1, 0, 1, 0, 0, -1, 0, 0};

int main () {
	while (scanf("%d %d %d", &l, &r, &c) != EOF && (l || r || c)) {
		getchar();
		
		memset(map, 0, sizeof(map));
		memset(book, 0, sizeof(book));

		int i, j, k;
		char ch;
		for (i = 0; i < l; i++) {
			for (j = 0; j < r; j++) {
				for (k = 0; k < c; k++) {
					ch = getchar();
					if (ch == '.')
						map[i][j][k] = 1;
					else if (ch == 'S') {
						startl = i;
						startr = j;
						startc = k;
						map[i][j][k] = 1;
						book[i][j][k] = 1;
					}
					else if (ch == 'E') {
						endL = i;
						endr = j;
						endc = k;
						map[i][j][k] = 1;
					}
				}
				getchar();
			}
			getchar();
		}

		ans = -1;
		bfs();
		printf(ans == -1 ? "Trapped!\n" : "Escaped in %d minute(s).\n", ans);
	}
	return 0;
}

void bfs() {
	queue <struct Node> node;
	struct Node n, nNew;
	int i;
	
	n.pc = startc; n.pl = startl; n.pr = startr; n.step = 0;
	node.push(n);
	
	while (!node.empty()) {
		n = node.front();
		
		for (i = 0; i < 6; i++) {
			n.pl += dir[i][0];
			n.pr += dir[i][1];
			n.pc += dir[i][2];
			
			if (check(n.pl, n.pr, n.pc)) {
				if (n.pl == endL && n.pr == endr && n.pc == endc) {
					ans = n.step + 1;
					return;
				}
				
				n.step++;
				book[n.pl][n.pr][n.pc] = 1;
				node.push(n);
				n.step--;
			}
			
			n.pl -= dir[i][0];
			n.pr -= dir[i][1];
			n.pc -= dir[i][2];
		}
		
		node.pop();
	}
	
}

bool check(int pl, int pr, int pc) {
	if (pl < 0 || pl >= l || pr < 0 || pr > r || pc < 0 || pc > c)
		return false;
	
	if (map[pl][pr][pc] == 0 || book[pl][pr][pc] == 1)
		return false;
		
	return true;
}
