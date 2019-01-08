/*
 *create at 2018-12-30 01:50:59
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

double getAns(double x) {
    return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int cases;
    scanf("%d", &cases);
    while (cases--) {
        double y;
        scanf("%lf", &y);

        if (y > getAns(100) || y < getAns(0)) {
            printf("No solution!\n");
            continue;
        }

        double l = 0, r = 100, mid, eps = 1e-6;
        while (r - l > eps) {
            mid = (l + r) / 2;
            if (getAns(mid) > y)
                r = mid;
            else
                l = mid;
        }
        printf("%.4lf\n", mid);
    }

    return 0;
}