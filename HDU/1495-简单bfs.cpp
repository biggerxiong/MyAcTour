#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

void bfs();
bool check(struct DATA);

int ans, s, n, m, book[105][105];

struct DATA {
	int x, y, sum;
	int step;
};

int main () {
	while (cin >> s >> n >> m) {
		if (s == 0 && n == 0 && m == 0)
			return 0;

		memset(book, 0, sizeof(book));
		
		if (s % 2 == 1)
			printf("NO\n");
		else {
			ans = 0;
			bfs();
			printf(ans == 0 ? "NO\n" : "%d\n", ans);
		}
	}
	return 0;
}

void bfs() {
	queue <struct DATA> node;
	struct DATA temp, tail;

	temp.x = 0;
	temp.y = 0;
	temp.sum = s;
	temp.step = 0;
	node.push(temp);

	while (!node.empty()) {
		temp = node.front();
		node.pop();

		if (check(temp)) {
			ans = temp.step;
			return;
		}
	
		if (book[temp.x][temp.y] == 1)
			continue;
		
		book[temp.x][temp.y] = 1;
		for (int i = 1; i < 7; i++) {
			switch(i) {
				case 1://可乐瓶倒进A
					if (temp.sum == 0 || temp.x == n)
						continue;
					if (temp.sum <= n - temp.x) {
						tail.sum = 0;
						tail.x = temp.x + temp.sum;
					}
					else {
						tail.sum = temp.sum - n + temp.x;
						tail.x = n;
					}
					tail.y = temp.y;
					break;
				case 2://可乐瓶倒进B
					if (temp.sum == 0 || temp.y == m)
						continue;
					if (temp.sum <= m - temp.y) {
						tail.sum = 0;
						tail.y = temp.y + temp.sum;
					}
					else {
						tail.sum = temp.sum - m + temp.y;
						tail.y = m;
					}
					tail.x = temp.x;
					break;
				case 3://A倒进B
					if (temp.x == 0 || temp.y == m)
						continue;

					tail.sum = temp.sum;
					tail.x = temp.x <= m - temp.y ? 0 : temp.x - m + temp.y;
					tail.y = temp.x <= m - temp.y ? temp.x + temp.y : m;
					break;
				case 4://B倒进A
					if (temp.y == 0 || temp.x == n)
						continue;

					tail.sum = temp.sum;
					tail.x = temp.y <= n - temp.x ? temp.x + temp.y : n;
					tail.y = temp.y <= n - temp.x ? 0 : temp.y - n + temp.x;
					break;
				case 5://A倒进可乐瓶
					if (temp.x == 0)
						continue;

					tail.y = temp.y;
					tail.sum = temp.sum + temp.x;
					tail.x = 0;
					break;
				case 6://B倒进可乐瓶
					if (temp.y == 0)
						continue;

					tail.x = temp.x;
					tail.sum = temp.sum + temp.y;
					tail.y = 0;
					break;
			}
			tail.step = temp.step + 1;
			node.push(tail);
		}
	}
}

bool check(struct DATA data) {
	int div = s / 2;
	if (data.sum == div && (data.x == div || data.y == div))
		return true;
	return false;
}
