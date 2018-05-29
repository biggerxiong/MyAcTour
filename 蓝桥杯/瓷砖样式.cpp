/*
 *create at 2018-05-16 19:10:46
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;
const int nn = 3, mm = 10;
int a[nn][mm];
long ans = 0;
map<int, int> m;

bool uni() {
    int cnt = 0, cur = 1;
    for(int i = 0; i < nn; i++) {
        for(int j = 0; j < mm; j++) {
            cnt += a[i][j] * cur;
            cur *= 2;
        }
    }
    if(m.count(cnt) == 1)
        return 0;
    else {
        m[cnt] = 1;
        return 1;
    }
}

void print() {
    for(int i = 0;  i < nn; i++) {
        for(int j = 0; j < mm; j++)
            printf("%d", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool bound(int x, int y) {
    if(x < 0 || y < 0 || x >= nn || y >= mm)
        return 0;
    return 1;
}

bool check() {
    for(int i = 0; i < nn; i++) 
        for(int j = 0; j < mm; j++) {
            if(i + 1 < nn && j + 1 < mm) {
                if((a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1]) % 4 == 0) 
                    return false;
        }
    }
    return true;
}

void dfs(int step) {
    if(step >= mm * nn) return;

    int x = step / mm, y = step % mm;
    // printf("x = %d, y = %d\n", x, y);

    if(a[x][y] == -1) {
        if(bound(x, y + 1) && a[x][y + 1] == -1) {
            for(int i = 0; i < 2; i++) {
                a[x][y] = a[x][y + 1] = i;
                dfs(step + 1);

                a[x][y] = a[x][y + 1] = -1;
            }
        }

        if(bound(x + 1, y) && a[x + 1][y] == -1) {
            for(int i = 0; i < 2; i++) {
                a[x][y] = a[x + 1][y] = i;
                dfs(step + 1);

                a[x][y] = a[x + 1][y] = -1;
            }
        }
    } else {
        if(x == nn - 1 && y == mm - 1) {
            // print();
            if(check() && uni()) {
                ans++;
                // print();
            }
            return;
        }

        dfs(step + 1);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        // freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    memset(a, -1, sizeof(a));
    dfs(0);
    printf("%ld\n", ans);

    return 0;
}