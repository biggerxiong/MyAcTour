/*
 *create at 2018-12-23 00:29:29
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
const int MAXN = 10005;

bool next_permutation(int *a, int n) {
    int i, j;
    for (i = n; i > 0; i--) {
        if (a[i - 1] < a[i]) {
            for (j = n; j > 0; j--) {
                if (a[j] > a[i])
                    break;
            }

            swap(a[i], a[j]);
            sort(a + i + 1, a + n);
            return true;
        }
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n, arr[MAXN], k;
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < k; i++) {
            next_permutation(arr, arr + n);
        }
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;
}