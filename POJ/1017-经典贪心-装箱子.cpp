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

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    //题解https://www.cnblogs.com/mycapple/archive/2012/08/23/2652070.html
    int a[7];
    int remain2[4] = {0, 5, 3, 1};
    while(scanf("%d %d %d %d %d %d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]) != EOF) {
        if(a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0 && a[6] == 0)
            break;

        int ans = a[6] + a[5] + a[4] + (a[3] + 3) / 4;
        int need2 = a[4] * 5 + remain2[a[3] % 4];
        if(need2 < a[2]) ans += (a[2] - need2 + 8) / 9;
        int need1 = ans * 36 - a[6] * 36 - a[5] * 25 - a[4] * 16 - a[3] * 9 - a[2] * 4;
        if(need1 < a[1]) ans += (a[1] - need1 + 35) / 36;

        cout << ans << endl;
    }

    return 0;
}