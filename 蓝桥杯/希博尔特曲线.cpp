/*
 *create at 2018-05-23 16:04:21
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

long long f(int n, int x, int y) {
    if (n == 0) return 1;
    int m = 1 << (n - 1);
    if (x <= m && y <= m) {
        return f(n - 1, y, x);
    }
    if (x > m && y <= m) {
        return 3LL * m * m + f(n - 1, m - y + 1 , m * 2 - x + 1); //  填空
    }
    if (x <= m && y > m) {
        return 1LL * m * m + f(n - 1, x, y - m);
    }
    if (x > m && y > m) {
        return 2LL * m * m + f(n - 1, x - m, y - m);
    }
}

int main() {
    int n, x, y;
    // scanf("%d %d %d", &n, &x, &y); 
    n = 3;
    x = 6;
    y = 3;
    printf("%lld", f(n, x, y));

    return 0;
}