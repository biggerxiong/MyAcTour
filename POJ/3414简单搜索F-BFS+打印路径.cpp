#include <iostream>
#include <cstdio>
using namespace std;

struct DATA {
	int a, b;
	int lastIndex, step;
	int opera; //1 fill(1), 2 fill(2), 3 pour(1,2), 4 pour(2,1), 5 drop(1), 6 drop(2)
}s[100000];

void bfs();
void print(int);
bool check(struct DATA);

int a, b, c, ans, ansIndex, book[105][105] = {0};

int main () {
	cin >> a >> b >> c;
	
	bfs();
	if (ans != -1) {
		cout << ans << endl;
		print(ansIndex);
	}
	else
		printf("impossible\n"); 
	
	return 0;
}

bool check(struct DATA data) {
	if (data.a == c || data.b == c)
		return true;
	return false;
}

void print(int index) {
	if (index == 0)
		return;
	else {
		print(s[index].lastIndex);

		switch(s[index].opera) {
			case 1:
				cout << "FILL(1)" << endl;
				break;
			case 2:
				cout << "FILL(2)" << endl;
				break;
			case 3:
				cout << "POUR(1,2)" << endl;
				break;
			case 4:
				cout << "POUR(2,1)" << endl;
				break;
			case 5:
				cout << "DROP(1)" << endl;
				break;
			case 6:
				cout << "DROP(2)" << endl;
				break;
		}
	}
}

void bfs() {
	int head = 0, tail = 0;
	s[head].a = 0;
	s[head].b = 0;
	s[head].lastIndex = 0;
	s[head].step = 0;
	tail++;

	while(head < tail) {
		if (check(s[head])) {
			ans = s[head].step;
			ansIndex = head;
			return ;
		}
		
		if (book[s[head].a][s[head].b] == 0) {
			book[s[head].a][s[head].b] = 1;
			for (int i = 1; i < 7; i++) {
				switch(i) {
					case 1:
						if (s[head].a == a)
							continue;
						s[tail].a = a;
						s[tail].b = s[head].b;
						s[tail].lastIndex = head;
						s[tail].step = s[head].step + 1;
						s[tail].opera = i;
						tail++;
						break;
					case 2:
						if (s[head].b == b)
							continue;
						s[tail].a = s[head].a;
						s[tail].b = b;
						s[tail].lastIndex = head;
						s[tail].step = s[head].step + 1;
						s[tail].opera = i;
						tail++;
						break;
					case 3:
						if (s[head].a == 0)
							continue;
						s[tail].a = s[head].a + s[head].b <= b ? 0 : s[head].a + s[head].b - b;
						s[tail].b = s[head].a + s[head].b <= b ? s[head].a + s[head].b : b;
						s[tail].lastIndex = head;
						s[tail].step = s[head].step + 1;
						s[tail].opera = i;
						tail++;
						break;
					case 4:
						if (s[head].b == 0)
							continue;
						s[tail].a = s[head].a + s[head].b <= a ? s[head].a + s[head].b : a;
						s[tail].b = s[head].a + s[head].b <= a ? 0 : s[head].a + s[head].b - a;
						s[tail].lastIndex = head;
						s[tail].step = s[head].step + 1;
						s[tail].opera = i;
						tail++;
						break;
					case 5:
						if (s[head].a == 0)
							continue;
						s[tail].a = 0;
						s[tail].b = s[head].b;
						s[tail].lastIndex = head;
						s[tail].step = s[head].step + 1;
						s[tail].opera = i;
						tail++;
						break;
					case 6:
						if (s[head].b == 0)
							continue;
						s[tail].a = s[head].a;
						s[tail].b = 0;
						s[tail].lastIndex = head;
						s[tail].step = s[head].step + 1;
						s[tail].opera = i;
						tail++;
						break;
				}
			}
		}
		
		head++;
	}
	ans = -1;
}
