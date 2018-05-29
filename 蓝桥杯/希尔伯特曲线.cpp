/*
 *create at 2018-05-16 17:26:15
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
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

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n, x, y;
    scanf("%d %d %d", &n, &x, &y); 
    printf("%lld", f(n, x, y));

    return 0;
}