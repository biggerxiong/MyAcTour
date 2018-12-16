/*
 *create at 2018-12-16 00:54:42
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
const int MAXN = 1005;

int map[MAXN][MAXN];
int visit[MAXN];
int degree[MAXN];
int n, m;

void dfs(int u) {
    if (visit[u] == 1)
        return;
    visit[u] = 1;
    for (int i = 1; i <= n; i++) {
        if (map[u][i] == 1) {
            dfs(i);
        }
    }
}

bool euler() {
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0)
            return false;
    }
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
        // freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        scanf("%d", &m);

        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        memset(degree, 0, sizeof(degree));
        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            map[a][b] = map[b][a] = 1;
            degree[a]++;
            degree[b]++;
        }
        
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (degree[i] % 2 == 1)
                cnt++;
        }

        if (cnt == 0) {
            if (euler())
                printf("1\n");
            else
                printf("0\n");
        }
        else {
            printf("0\n");
        }
    }

    return 0;
}