/*
 *create at 2018-06-17 13:15:50
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

    int nums[100];
    int index = 0;
    while(scanf("%d", &nums[index++]) != EOF && nums[index - 1] != 0);
    for(int i = index - 2; i >= 0; i--)
        printf("%d ", nums[i]);

    return 0;
}