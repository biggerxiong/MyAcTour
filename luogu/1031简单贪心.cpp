/*
 *create at 2018-08-18 19:29:51
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

    int n, sum = 0;
    int a[105];

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int avg = sum / n;
    for(int i = 0; i < n; i++) {
        a[i] -= avg;
    }

    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        // printf("i = %d, a[i] = %d\n", i, a[i]);
        if(a[i] != 0) {
            a[i + 1] += a[i];
            a[i] = 0;
            ans++;
        }
    }
    cout << ans;

    return 0;
}