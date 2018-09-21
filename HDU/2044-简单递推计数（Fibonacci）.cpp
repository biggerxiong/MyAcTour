/*
 *create at 2018-09-21 09:04:36
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
const int MAXN = 10005;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    long long dp[55] = {0, 1, 2};
    for(int i = 3; i <= 48; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int cases;
    cin >> cases;
    while(cases--) {
        int a, b;
        cin >> a >> b;
        cout << dp[b - a] << endl;
    }

    return 0;
}