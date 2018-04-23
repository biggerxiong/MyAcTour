/*
 *creat at 2018-04-23 19:57:18
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

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    int n, k;
    long long ans = 0;

    cin >> n >> k;
    
    if(k != 0) {
        for(int i = k; i <= n; i++) {
            ans += n - i;
        }
        for(int i = k + 1; i <= n - k; i++) {
            ans += (n - i) / k;
        }
    } else {
        for(int i = k; i <= n; i++) {
            ans += n - i + 1;
        }
        for(int i = k + 1; i <= n - k; i++) {
            ans += n - i;
        }
    }

    printf("%lld\n", ans);

    return 0;
}