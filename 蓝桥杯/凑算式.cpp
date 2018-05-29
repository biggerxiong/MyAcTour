/*
 *create at 2018-05-27 16:47:31
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

int ans = 0;
int book[10], path[10];
void dfs(int step) {
    if(step == 9) {
        double a = path[0];
        double b = 1.0 * path[1] / path[2];
        double c = 1.0 * (path[3] * 100 + path[4] * 10 + path[5]) / (path[6] * 100 + path[7] * 10 + path[8]);
        if(((a + b + c) - 10) <= 0.000001 && ((a + b + c) - 10) >= -0.000001) {
            for(int i = 0; i < 10; i++)
                printf("%d ", path[i]);
            printf("  %lf %lf %lf\n", a, b, c);

            ans++;
        }
        return;
    }

    for(int i = 1; i < 10; i++) {
        if(book[i] == 0) {
            book[i] = 1;
            path[step] = i;
            dfs(step + 1);
            book[i] = 0;
            path[step] = 0;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    dfs(0);
    printf("ans = %d\n", ans);

    return 0;
}
