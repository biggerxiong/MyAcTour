/*
 *create at 2018-09-10 14:18:35
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
const int MAXN = 1005;

int n, r;
struct Seg {
    double s, e;
}seg[MAXN];

bool cmp(Seg a, Seg b) {
    if(fabs(a.e - b.e) > 0.0000001) // 浮点数不能直接比较是否相等
        return a.e < b.e;
    return a.s < b.s;
}

Seg getSeg(int a, int b) {
    Seg temp;
    temp.s = a - sqrt(r * 1.0 * r - b * 1.0 * b);
    temp.e = a + sqrt(r * 1.0 * r - b * 1.0 * b);
    return temp;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n;
    int cases = 0;
    while(scanf(" %d %d", &n, &r) != EOF) {
        cases++;
        if(n == 0 && r == 0)
            break;

        int flag = 1;
        int a, b;
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            if(b > r) flag = 0;
            seg[i] = getSeg(a, b);
        }

        if(flag == 0) {
            printf("Case %d: -1\n", cases);
            continue;
        }

        sort(seg, seg + n, cmp);
        int ans = 1;
        double last = seg[0].e;
        for(int i = 1; i < n; i++) {
            if(last < seg[i].s) {
                ans++;
                last = seg[i].e;
            }
        }

        printf("Case %d: %d\n", cases, ans);
    }

    return 0;
}