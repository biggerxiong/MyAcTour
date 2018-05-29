/*
 *create at 2018-05-23 15:31:58
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
const int n = 3;
const int m = 10;

int a[n][m], ans = 0;;

bool check() {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++)
            if((a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1]) % 4 == 0)
                return false;
    }
    return true;
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void dfs(int step) {
    int x = step / m, y = step % m;
    // printf("step = %d\n", step);
    if(a[x][y] == -1) {
        if(y + 1 < m && a[x][y + 1] == -1) { // 横着贴
            // printf("1111\n");
            for(int i = 0; i < 2; i++) {
                a[x][y] = a[x][y + 1] = i;
                dfs(step + 1);
            }
            a[x][y] = a[x][y + 1] = -1;
        }
        if(x + 1 < n && a[x + 1][y] == -1) { // 竖着贴
            // printf("2222\n");
            for(int i = 0; i < 2; i++) {
                a[x][y] = a[x + 1][y] = i;
                dfs(step + 1);
            }
            a[x][y] = a[x + 1][y] = -1;
        }
    } else {
        if(x == n - 1 && y == m - 1) {
            if(check()) {
                // print();
                ans++;
            }
        } else if(x >= n || y >= m) {
            return;
        } else {
            dfs(step + 1);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    memset(a, -1, sizeof(a));
    dfs(0);
    printf("ans = %d\n", ans);

    return 0;
}