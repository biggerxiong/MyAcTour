/*
 *create at 2018-12-09 09:52:56
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;
#ifndef ONLINE_JUDGE
    #define db(str, arg, ...) printf(str, arg, ##__VA_ARGS__);
#else
    #define db(str, arg, ...) ;
#endif
#define inf 0x3f3f3f3f
const int MAXN = 505;

int map[MAXN][MAXN];
int in[MAXN];
int ans[MAXN];

int main() {
    #ifndef ONLINE_JUDGE
        // freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif
    
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int a, b;
        memset(map, 0, sizeof(map));
        memset(in, 0, sizeof(in));
        memset(ans, 0, sizeof(ans));

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            if (map[a][b] == 0) {
                map[a][b] = 1;
                in[b]++;
            }
        }

        int cnt = 0;
        int k = 1;
        for (int j = 1; j <= n; j++) {
            for(k = 1; in[k] != 0; k++);

            // printf("get k = %d\n", k);
            ans[cnt++] = k;
            for (int i = 1; i <= n; i++) {
                if (map[k][i] == 1) {
                    // printf("i = %d --\n", i);
                    in[i]--;
                }
            }
            in[k]--;
        }

        printf("%d", ans[0]);
        for (int i = 1; i < cnt; i++) {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }

    return 0;
}
