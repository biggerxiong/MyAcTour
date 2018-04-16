/*
 *creat at 2018-04-16 18:20:53
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 100005

// 记忆化
long long a[31][MAXN] = {0};

long long g(int k, int i) {
    if(i == 0)
        return 0;
    else if(k == 0) {
        return 1;
    }
    else if(k == 1) {
        if(i == 1)
            return 2;
        else
            return 3;
    }

    if(i >= MAXN) {
        if(i <= (1 << k) / 2)
            return g(k - 1, i) * 2;
        else
            return g(k - 1, 1 << (k - 1)) * 2 + g(k - 1, i - (1 << (k - 1)));
    }
    else {
        if(a[k][i] != 0) 
            return a[k][i];
        else {
            if(i <= (1 << k) / 2)
                return a[k][i] = g(k - 1, i) * 2;
            else
                return a[k][i] = g(k - 1, 1 << (k - 1)) * 2 + g(k - 1, i - (1 << (k - 1)));
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    int cases, casesTemp = 0, k, a, b;
    cin >> cases;
    while(casesTemp++ < cases) {
        printf("Case %d: ", casesTemp);

        scanf("%d %d %d", &k, &a, &b);
        // printf("g(%d, %d) = %lld, g(%d, %d) = %lld\n", k, a-1, g(k, a - 1), k, b, g(k, b));
        printf("%lld\n", g(k, b) - g(k, a - 1));
    }

    return 0;
}