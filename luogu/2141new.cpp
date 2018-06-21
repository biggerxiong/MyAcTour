/*
 *create at 2018-06-17 14:34:52
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
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
        freopen("testdata.in", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int count[10005] = {0};
    int n, temp;
    int nums[105], x;

    scanf("%d", &x);
    for(int i = 0; i < x; i++) {
        scanf("%d", &temp);
        if(count[temp] == 0) {
            nums[n++] = temp;
            count[temp] = 1;
        }
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int s = nums[i] + nums[j];
            if(s <= 10000 && count[s] == 1)
                ans.push_back(s);
        }
    }

    sort(ans.begin(), ans.end());
    auto t = unique(ans.begin(), ans.end());
    printf("%d\n", t - ans.begin());

    return 0;
}