/*
 *create at 2018-09-21 21:30:58
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

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int cases;
    scanf("%d", &cases);
    while(cases--) {
        memset(dp, 0, sizeof(dp));
        int n, c;
        int val[MAXN], v[MAXN];

        scanf("%d %d", &n, &c);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &val[i]);
        }
        for(int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= c; j++) {
                if(j >= v[i]) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + val[i]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        printf("%d\n", dp[n][c]);
    }

    return 0;
}