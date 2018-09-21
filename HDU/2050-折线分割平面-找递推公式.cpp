/*
 *create at 2018-09-21 09:10:08
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

    long long dp[10005] = {0, 2, 7};
    for(int i = 3; i <= 10000; i++) {
        dp[i] = dp[i - 1] + (i - 1) * 4 + 1;
    }

    int cases;
    cin >> cases;
    while(cases--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}