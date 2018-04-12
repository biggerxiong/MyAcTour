#include<iostream>
#include<stdio.h>
using namespace std;

struct DATA {
	int x, y;
	int dirx, diry;
	char dir;
};

int book[105][105];
void turn(struct DATA *s, int i, char dir) {
	if (dir == 'R') {
		switch (s[i].dir) {
			case 'E' ://n
				s[i].diry = -1;
				s[i].dirx = 0;
				s[i].dir = 'N';
				break;
			case 'S' ://e
				s[i].dirx = 1;
				s[i].diry = 0;
				s[i].dir = 'E';
				break;
			case 'W' ://s
				s[i].dirx = 0;
				s[i].diry = 1;
				s[i].dir = 'S';
				break;
			case 'N' ://w
				s[i].dirx = -1;
				s[i].diry = 0;
				s[i].dir = 'W';
				break;
		}
	}
	else if (dir == 'L') {
		switch (s[i].dir) {
			case 'E' ://n
				s[i].diry = -1;
				s[i].dirx = 0;
				s[i].dir = 'N';
				break;
			case 'S' ://e
				s[i].dirx = 1;
				s[i].diry = 0;
				s[i].dir = 'E';
				break;
			case 'W' ://s
				s[i].dirx = 0;
				s[i].diry = 1;
				s[i].dir = 'S';
				break;
			case 'N' ://w
				s[i].dirx = -1;
				s[i].diry = 0;
				s[i].dir = 'W';
				break;
		}
	}
}
int main() {
	struct DATA s[10005];
	int cases;
	int a, b, i, j;
	int n, step;
	char ch;
	
	cin >> cases;
	while (cases--) {
		cin >> a >> b;
		for (i = 1; i <= a; i++)			// reset
			for (j = 1; j <= b; j++)
				book[i][j] = 0;
				
		cin >> n >> step;
		for (i = 1; i <= n; i++) {
			cin >> s[i].x >> s[i].y;
			getchar();
			cin >> s[i].dir;
			
			book[s[i].x][s[i].y] = 1;
			switch (s[i].dir) {
				case 'N' :
					s[i].diry = -1;
					s[i].dirx = 0;
					break;
				case 'E' :
					s[i].dirx = 1;
					s[i].diry = 0;
					break;
				case 'S' :
					s[i].dirx = 0;
					s[i].diry = 1;
					break;
				case 'W' :
					s[i].dirx = -1;
					s[i].diry = 0;
					break;
			}
		}
		
//		for (i = 1; i <= a; i++) {
//			for (j = 1; j <= b; j++)
//				printf("%d ", book[i][j]);
//			printf("\n");
//		}
//		printf("\n");
		
		int index, k;
		int flag = 1;
		for (i = 0; i < step; i++) {
			cin >> index;
			getchar();
			cin >> ch;
			cin >> k;
			
			if (ch != 'F')
				turn(s, index, ch);
			
			for (j = 0; j < k && flag; j++) {
				book[s[index].x][s[index].y] = 0;
				
				s[index].x = s[index].x + s[index].dirx;
				s[index].y = s[index].y + s[index].diry;
				
				if (s[index].x < 0 || s[index].x > a || s[index].y < 0 || s[index].y > b) {
					printf("Robot %d crashes into the wall\n", index);
					flag = 0;
					break;
				}
				else if (book[s[index].x][s[index].y] == 1) {
					int c;
					for (c = 1; c <= n; c++) {
						if (s[c].x == s[index].x && s[c].y == s[index].y && c != index)
							break;
					}
					printf("Robot %d crashes into robot %d\n", index, c);
					flag = 0;
					break;
				}
				
				book[s[index].x][s[index].y] = 1;
			}
		}
		if (flag)
			cout << "OK" << endl;
	}
	
	return 0;
}
