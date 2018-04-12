#include <cstdio>
#include <iostream>
using namespace std;

struct DATA{
	int x, y;
	int lastIndex;
}s[100000];

int bfs();
void print(int);
bool border(int, int);
bool check(int, int);

int map[5][5], dir[4][4] = {1, 0, -1, 0, 0, 1, 0, -1};

int main () {
	int i, j;
	for (i = 0; i < 5; i++) 
		for (j = 0; j < 5; j++) 
			cin >> map[i][j];
	
	print(bfs());

	return 0;
}

bool border(int i, int j) {
	if (i < 0 || i >= 5 || j < 0 || j >= 5)
		return false;
	return true;
}

bool check(int i, int j) {
	if (i == 4 && j == 4)
		return true;
	return false;
}

void print(int index) {
	if (index == 0) {
		printf("(0, 0)\n");
		return;
	}
	else {
		print(s[index].lastIndex);
		printf("(%d, %d)\n", s[index].x, s[index].y);
	}
}
int bfs() {
	int head, tail;
	head = tail = 0;

	s[head].x = 0;
	s[head].y = 0;
	s[head].lastIndex = 0;
	tail++;

	while (head < tail) {
		if (check(s[head].x, s[head].y)) {
			return head;
		}

		for (int i = 0; i < 4; i++) {
			int tempx = s[head].x + dir[i][0];
			int tempy = s[head].y + dir[i][1];

			if (border(tempx, tempy) && map[tempx][tempy] == 0) {
				s[tail].x = tempx;
				s[tail].y = tempy;
				s[tail].lastIndex = head;
				tail++;
			}
		}
		
		head++;
	}
}
