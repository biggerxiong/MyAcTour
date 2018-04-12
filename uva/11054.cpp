/*
 *creat at 2018-04-11 21:07:38
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

int n;
int a[1000005];
long long ans, temp;

int main () {
    while(scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        ans = 0;
        temp = 0;
        for(int i = 0; i < n; i++) {
            temp += a[i];
            ans += abs(temp);
        }

        cout << ans << endl;
    }
    return 0;
}