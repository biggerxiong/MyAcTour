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
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int nums[105], count[10005] = {0};
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        count[nums[i]]++;
    }

    sort(nums, nums + n);
    vector<int> v;
    v.push_back(nums[0]);
    for(int i = 1; i < n; i++)
        if(nums[i] != nums[i - 1])
            v.push_back(nums[i]);


    vector<int> ans;
    for(auto it1 = v.begin(); it1 != v.end(); it1++) {
        for(auto it2 = it1 + 1; it2 != v.end(); it2++) {
            int s = (*it1) + (*it2);
            if(s <= 10000 && count[s] != 0) {
                ans.push_back(s);
                // printf("%d %d, sum = %d\n", *it1, *it2, s);
            }
        }
    }

    sort(ans.begin(), ans.end());
    auto t = unique(ans.begin(), ans.end());
    printf("%d\n", t - ans.begin());

    return 0;
}