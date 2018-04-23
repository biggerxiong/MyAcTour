/*
 *creat at 2018-04-23 20:20:52
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

    vector<int> v;
    int a, b;
    int time, cost;
    int n;

    cin >> n;
    while(n--) {
        scanf("%d %d", &a, &b);
        v.push_back(a * 60 + b);
    }
    scanf("%d %d %d", &cost, &a, &b);

    sort(v.begin(), v.end());

    time = a * 60 + b;
    auto it = lower_bound(v.begin(), v.end(), time - cost);

    // printf("time = %d, cost = %d, it = %d\n", time, cost, *it);
    if((*it) == time - cost)
        printf("%d %d\n", (*it) / 60, (*it) % 60);
    else
        printf("%d %d\n", (*(it - 1)) / 60, (*(it - 1)) % 60);

    return 0;
}