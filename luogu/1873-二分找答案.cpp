/*
 *create at 2018-12-30 01:08:03
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
const int MAXN = 1000005;

long long tree[MAXN];
long long ans;
long long n, m;

long long check(long long h) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i] > h)
            sum += tree[i] - h;
    }
    return sum;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &tree[i]);

    long long l = 0, r = 2000000000L, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid) < m) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    printf("%lld\n", r);

    return 0;
}