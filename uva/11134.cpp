/*
 *creat at 2018-04-11 20:12:09
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f  3f3f
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornr(i, n) for(int i = n - 1; i >= 0; i--)

int n;

struct Data {
    int id;
    int lx, ly, rx, ry;
    int ansx, ansy;
}s[5005];

bool cmpx(Data a, Data b) {
    if(a.lx != b.lx)
        return a.lx < b.lx;
    return a.rx < b.rx;
}

bool cmpy(Data a, Data b) {
    if(a.ly != b.ly)
        return a.ly < b.ly;
    return a.ry < b.ry;
}

bool cmp(Data a, Data b) {
    return a.id < b.id;
}

bool solve() {
    int i;

    sort(s + 1, s + n + 1, cmpx);
    for(i = 1; i <= n; i++) {
        if(s[i].lx > i || s[i].rx < i) {
            return false;
        }
        else {
            s[i].ansx = i;
        }
    }

    sort(s + 1, s + n + 1, cmpy);
    for(i = 1; i <= n; i++) {
        if(s[i].ly > i || s[i].ry < i) {
            return false;
        }
        else {
            s[i].ansy = i;
        }
    }

    sort(s + 1, s + n + 1, cmp);
    for(i = 1; i <= n; i++)
        printf("%d %d\n", s[i].ansx, s[i].ansy);

    return true;
}

int main () {
    freopen("in.txt", "r", stdin);

    int i;
    while(scanf("%d", &n) && n) {
        for(i = 1; i <= n; i++) {
            scanf("%d %d %d %d", &s[i].lx, &s[i].ly, &s[i].rx, &s[i].ry);
            s[i].id = i;
        }
        if(!solve())
            printf("IMPOSSIBLE\n");
    }

    return 0;
}