/*
 *create at 2018-12-30 00:48:40
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

int search(int a[], int l, int r, int num) {
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] == num) 
            return mid;
        else if (a[mid] > num) 
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n, m;
    int a[MAXN], b[MAXN];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    sort(b, b + m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (search(b, 0, m - 1, a[i]) != -1)
            printf("%d ", a[i]);
    }

    return 0;
}