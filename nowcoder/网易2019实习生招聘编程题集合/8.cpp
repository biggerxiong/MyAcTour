/*
 *creat at 2018-04-23 20:30:09
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 10005

long long w, a[MAXN], n, ans;

void dfs(int step, long long cur) {
    ans++;
    for(int i = step + 1; i < n; i++) {
        if(cur + a[i] <= w) {
            dfs(i, cur + a[i]);
        } else {
            return;
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    long long sum = 0;
    cin >> n >> w;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    if(sum <= w)
        ans = pow(2, n);
    else {
        sort(a, a + n);
        ans = 0;
        dfs(-1, 0);
    }
    printf("%lld\n", ans);

    return 0;
}