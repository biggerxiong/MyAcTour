/*
 *create at 2018-09-21 08:53:48
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

    long long dp[60] = {0, 1, 2, 3, 4};
    for(int i = 5; i <= 55; i++) {
        dp[i] = dp[i - 3] + dp[i - 1];
    }

    int n;
    while(cin >> n && n) {
        cout << dp[n] << endl;
    }
    return 0;
}