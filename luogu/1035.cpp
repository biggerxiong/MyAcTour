/*
 *create at 2018-06-17 12:07:57
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

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n;
    double k;
    cin >> k;

    double sum = 0;
    for(n = 1; ; n++) {
        sum += 1.0 / n;
        if(sum > k)
            break;
    }
    cout << n << endl;

    return 0;
}