/*
 *create at 2018-09-10 14:18:35
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
int dp[MAXN][MAXN] = {0};
char map[MAXN][MAXN];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int cases;
    scanf(" %d", &cases);
    while(cases--) {
        int n, m;
        scanf(" %d %d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf(" %s", map[i]);

        // init
        int flag = 1;
        for(int i = 0; i < m; i++) {
            if(map[0][i] == '#') flag = 0;
            dp[0][i] = flag;
        }
        flag = 1;
        for(int i = 0; i < n; i++) {
            if(map[i][0] == '#') flag = 0;
            dp[i][0] = flag;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(map[i][j] == '#')
                    dp[i][j] = 0;
                else 
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        printf("Existuje %d ruznych cest.\n", dp[n - 1][m - 1]);
    }

    return 0;
}