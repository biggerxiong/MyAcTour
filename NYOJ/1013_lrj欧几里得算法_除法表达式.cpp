/*
 *creat at 2018-04-16 20:19:56
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 10005

long long gcd(long long a, long long b) {
    long long c = a % b;
    if(c == 0)
        return b;
    else
        return gcd(b, c);
}

int k, x[MAXN];

bool solve() {
    int i, temp = x[1];

    temp /= gcd(temp, x[0]);
    if(temp == 1)
        return true;

    for(i = 2; i < k; i++) {
        temp /= gcd(temp, x[i]);
        if(temp == 1)
            return true;
    }
    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    int cases;
    cin >> cases;
    while(cases--) {
        char ch = 0;
        for(k = 0; ch != '\n'; k++) {
            scanf("%d%c", &x[k], &ch);
        }
        
        // printf("k = %d\n", k);
        printf(solve() ? "YES\n" : "NO\n");
    }

    return 0;
}