/*
 *create at 2018-05-24 11:21:27
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
int c[50] = {0};
int width, ans;
char path[50][50];

void init() {
    for(int i = 1; i < 50; i++) 
        c[i] = c[i - 1] + i;
    ans = 0;
    memset(path, 0, sizeof(path));
}

int getc(int num) {
    for(int i = 1; i < 50; i++) {
        if(num == c[i - 1])
            return i;
    }
    return 0;
}

void print() {
    printf("\n");
    for(int i = 1; i <= width; i++) {
        printf("%s\n", path[i]);
    }
}

bool check(int a, int b) {
    int i, j;
    for(i = width - 1; i >= 0; i--) {
        for(j = 0; j < i; j++) {
            if(path[i + 1][j] == path[i + 1][j + 1]) {
                path[i][j] = 'A';
                a--;
            } else {
                path[i][j] = 'B';
                b--;
            }
        }

        if(a < 0 || b < 0)
            return false;
        path[i][j] = '\0';
    }
    if(a == 0 && b == 0)
        return true;
}

void dfs(int step, int a, int b) {
    // printf("step = %d, a = %d, b = %d\n", step, a, b);
    if(step == width) {
        // printf("%s\n", path[width]);
        if(check(a, b)) {
            print();
            ans++;
        }
        return;
    }

    if(a > 0) {
        path[width][step] = 'A';
        dfs(step + 1, a - 1, b);
        path[width][step] = 0;
    }
    if(b > 0) {
        path[width][step] = 'B';
        dfs(step + 1, a, b - 1);
        path[width][step] = 0;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    cin >> a >> b;
    init();
    width = getc(a + b);
    if(width != 0) dfs(0, a, b);
    printf("%d\n", ans);
    
    return 0;
}