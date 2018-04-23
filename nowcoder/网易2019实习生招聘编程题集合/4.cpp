/*
 *creat at 2018-04-23 19:42:57
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

    int n, op = 0;
    char str[MAXN];
    char ans[MAXN] = "ESWNESW\0";

    scanf(" %d %s", &n, str);
    for(int i = 0; i < n; i++) {
        if(str[i] == 'L')
            op--;
        else
            op++;
    }

    op %= 4;
    op += 3;
    // printf("op = %d\n", op);
    printf("%c\n", ans[op]);

    return 0;
}