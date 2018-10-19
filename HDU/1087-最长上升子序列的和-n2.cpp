/*
 *create at 2018-10-20 00:58:28
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

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n;
    int a[MAXN];
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int dp[MAXN] = {a[0], 0};
        int ans = -1;
        for (int i = 1; i < n; i++) {
            int maxn = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (a[i] > a[j]) {
                    maxn = max(maxn, dp[j]);
               }
            }
            dp[i] = maxn + a[i];
            ans = max(dp[i], ans);
        }
        printf("%d\n", ans);
    }

    return 0;
}