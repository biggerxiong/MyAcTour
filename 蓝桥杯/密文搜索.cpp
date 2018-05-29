/*
 *create at 2018-05-24 20:04:36
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <ctime>
#include <iostream>
using namespace std;
#ifndef ONLINE_JUDGE
    #define db(str, arg, ...) printf(str, arg, ##__VA_ARGS__);
#else
    #define db(str, arg, ...) ;
#endif
#define inf 0x3f3f3f3f
const int MAXN = 1024*1024+5;

char str[MAXN];
map<string, int> dict;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    int start = clock();

    cin >> str;
    int len = strlen(str);
    int t, ans = 0;

    for(int i = 0; i + 7 < len; i++) {
        string s = string(str + i, str + i + 8);
        sort(s.begin(), s.end());
        dict[s]++;
    }

    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if(dict.count(s) != 0) ans += dict[s];
    }

    printf("%d\n", ans);
    printf("%.3lf\n",double(clock()-start)/CLOCKS_PER_SEC);

    return 0;
}