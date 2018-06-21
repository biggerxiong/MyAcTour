/*
 *create at 2018-06-17 11:55:21
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

bool check(int a, int b, int c) {
    int book[10] = {0};

    while(a) {
        book[a % 10] = 1;
        a /= 10;

        book[b % 10] = 1;
        b /= 10;

        book[c % 10] = 1;
        c /= 10;
    }

    int sum = 0;
    for(int i = 1; i < 10; i++)
        sum += book[i];
    return sum == 9;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    for(int i = 123; i < 333; i++) {
        if(check(i, i * 2, i * 3))
            printf("%d %d %d\n", i, i * 2, i * 3);
    }

    return 0;
}