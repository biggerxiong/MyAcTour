/*
 *create at 2018-10-20 00:28:59
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
const int MAXN = 100005;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int cases;
    scanf("%d", &cases);
    int t = 1;
    while (t <= cases) {
        printf("Case %d:\n", t++);

        int s = 1, e = 0, n, S = 0, E = 0;
        int a[MAXN], dp[MAXN] = {0};
        int maxn = -9999;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > dp[i - 1] + a[i]) {
                dp[i] = a[i];
                s = i;
                e = i;
            } else {
                dp[i] = dp[i - 1] + a[i];
                e++;
            }

            if(dp[i] > maxn) {
                // printf("dp = %d, maxn = %d\n", dp[i], maxn);
                // printf("**e = %d, E = %d\n", e, E);
                S = s;
                E = e;
                maxn = dp[i];
            }
        }
        // for (int i = 0; i <= n; i++)
        //     printf("%d ", dp[i]);
        // printf("\n");
        printf("%d %d %d\n", maxn, S, E);
        if(t <= cases) printf("\n");
    }

    return 0;
}