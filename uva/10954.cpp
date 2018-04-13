/*
 *creat at 2018-04-13 20:35:12
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 10005

class cmpInt{
public:
    bool operator() (const int& a, const int& b) const {
        return a > b;
    }
};

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    int n, temp;
    int i, a, b, ans;
    while(scanf("%d", &n) && n) {
        priority_queue<int, vector<int>, cmpInt> q;
        for(i = 0; i < n; i++) {
            scanf("%d", &temp);
            q.push(temp);
        }

        ans = 0;
        while(q.size() > 1) {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            ans += a + b;
            // printf("get %d %d\n", a, b);
            q.push(a + b);
        }

        printf("%d\n", ans);
    }
    return 0;
}