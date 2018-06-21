/*
 *create at 2018-06-17 12:24:36
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

    int n, x, ans = 0;
    cin >> n >> x;
    for(int i = 0; i <= n; i++) {
        int temp = i;
        while(temp) {
            if(temp % 10 == x) ans++;
            temp /= 10;
        }
    }
    cout << ans << endl;

    return 0;
}