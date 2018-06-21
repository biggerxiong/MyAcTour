/*
 *create at 2018-06-17 12:18:46
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

    long long x, n;
    cin >> x >> n;

    int ans = 0;
    ans += 250 * 5 * (n / 7);

    n %= 7;
    for(int i = 0; i < n; i++) {
        if((i + x) % 7 != 0 && (i + x) % 7 != 6)
            ans += 250;
    }
    cout << ans << endl;

    return 0;
}