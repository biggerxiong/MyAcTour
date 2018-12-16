/*
 *create at 2018-12-08 22:14:33
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#ifndef ONLINE_JUDGE
    #define db(str, arg, ...) printf(str, arg, ##__VA_ARGS__);
#else
    #define db(str, arg, ...) ;
#endif
#define inf 0x3f3f3f3f
const int MAXN = 105;

int dir[8][2] = {1,0,0,1,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};
int cnt = 0, m, n;
char map[MAXN][MAXN];
int visited[MAXN][MAXN];

bool check(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    if (map[x][y] != '@')
        return false;
    if (visited[x][y] != 0)
        return false;
    return true;
}

void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if (check(nx, ny)) {
            visited[nx][ny] = cnt;
            dfs(nx, ny);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n; i++) {
            scanf(" %s", map[i]);
            db("read %s\n", map[i]);
        }

        cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == '@' && !visited[i][j]) {
                    cnt++;
                    visited[i][j] = cnt;
                    dfs(i, j);
                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}