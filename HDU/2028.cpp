/*
 *creat at 2018-03-15 16:07:46
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornr(i, n) for(int i = n - 1; i >= 0; i--)

int gcd(int a, int b) {
    int c = a % b;
    if (c == 0)
        return b;
    else
        return gcd(b, c);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main () {
    int ans;
    int n, a, b;

    while (scanf("%d ", &n) != EOF) {
        scanf("%d", &a);
        ans = a;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d", &b);
            ans = lcm(ans, b);
        }
        printf("%d\n", ans);
    }

    return 0;
}