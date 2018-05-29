/*
 *create at 2018-05-24 19:19:51
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

vector<int> v;
int a[MAXN] = {0};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n, k, temp, ans = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a[temp]++;
    }

    for(int m = 0; m < k; m++) {
        unsigned int i;
        v.clear();
        for(i = m; i < MAXN; i += k) {
            v.push_back(a[i]);
        }

        for(i = 0; i < v.size(); v++)
    }

    return 0;
}