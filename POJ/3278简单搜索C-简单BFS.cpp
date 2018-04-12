#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Node{
	int index;
	int step;
};

void bfs();
bool check(int );
int book[100005], ans, start, end;

int main () {
	scanf("%d %d", &start, &end);
	if (start == end)
		cout << 0 << endl;
	else {
		memset(book, 0, sizeof(book));
		book[start] = book[end] = 1;

		bfs();

		cout << ans << endl;
	}
	return 0;
}

void bfs() {
	queue <struct Node> node;
	struct Node n, nNew;

	n.index = start;
	n.step = 0;

	node.push(n);
	while (!node.empty()) {
		n = node.front();

		int temp = n.index + 1;
		if (temp == end) {ans = n.step + 1; return;}
		if (check(temp)) {
			book[temp] = 1;
			nNew.index = temp;
			nNew.step = n.step + 1;
			node.push(nNew);
		}

		temp = n.index - 1;
		if (temp == end) {ans = n.step + 1; return;}
		if (check(temp)) {
			book[temp] = 1;
			nNew.index = temp;
			nNew.step = n.step + 1;
			node.push(nNew);
		}

		temp = n.index * 2;
		if (temp == end) {ans = n.step + 1; return;}
		if (check(temp)) {
			book[temp] = 1;
			nNew.index = temp;
			nNew.step = n.step + 1;
			node.push(nNew);
		}

		node.pop();
	}
}

bool check(int index) {
	if (index < 0 || index > 100000)
		return false;
	if (book[index] == 1)
		return false;

	return true;
}
