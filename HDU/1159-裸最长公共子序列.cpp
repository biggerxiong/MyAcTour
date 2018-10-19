/*
 *create at 2018-10-19 23:39:33
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

int dp[MAXN][MAXN], len1, len2;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    char str1[MAXN], str2[MAXN];
    while(scanf(" %s %s", str1, str2) != EOF) {
        memset(dp, 0, sizeof(dp));

        len1 = strlen(str1);
        len2 = strlen(str2);

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        } 
        printf("%d\n", dp[len1][len2]);
    }

    return 0;
}