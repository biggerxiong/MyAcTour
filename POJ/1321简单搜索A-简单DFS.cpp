#include <stdio.h>

void dfs(int, int );
void clear(int *);
int n, k, map[10][10], book[10], m, ans;

int main () {
	while (scanf("%d %d", &n, &k) != EOF && (n != -1 && k != -1)) {
		getchar();

		char ch;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ch = getchar();
				if (ch == '#')
					map[i][j] = 1;
				else 
					map[i][j] = 0;
			}
			getchar();
		}

		m = 0;
		ans = 0;
		clear(book);
		dfs(0, 0);
		printf("%d\n", ans);
	}

	return 0;
}

void dfs(int i, int j) {
	if (m == k) 
//		printf("%d %d ans++\n", i, j, ans++);
		ans++;
	else if (i >= n || j >= n)
		return ;
	else {
		int key = 0;
		for (; j < n; j++) {
			if (map[i][j] == 1 && book[j] == 1) {
				book[j] = 0;
				map[i][j] = 0;
				m++;
				dfs(i + 1, 0);
				book[j] = 1;
				map[i][j] = 1;
				m--;
				
				key = 1;
			}
		}
		if (key)
			dfs(i + 1, 0);
	}
}

void clear(int num[]) {
	for (int i = 0; i < 10; i++)
		num[i] = 1;
}
