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
const int MAXN = 100005;

struct Data {
    int dis, cost;
    double quo;
}cow[MAXN];

bool cmp(Data a, Data b) {
    return a.quo > b.quo;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n;
    while(scanf(" %d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &cow[i].dis, &cow[i].cost);
            cow[i].quo = cow[i].cost * 1.0 / cow[i].dis;
        }

        sort(cow, cow + n, cmp);
        long long time = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            ans += cow[i].cost * time;
            time += cow[i].dis * 2;
        }

        printf("%lld\n", ans);
    }

    return 0;
}