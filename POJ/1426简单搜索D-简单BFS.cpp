#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

unsigned long long bfs(int);

int main () {
	int n;
	while (scanf("%d", &n) != EOF && n) {
		cout << bfs(n) << endl;
	}
}

unsigned long long bfs(int n) {
	queue <unsigned long long> node;
	unsigned long long temp;
	node.push(1);

	while (1) {
		temp = node.front();
		node.pop();

		if (temp % n == 0)
			return temp;
		else {
			node.push(temp * 10);
			node.push(temp * 10 + 1);
		}
	}
	
}

