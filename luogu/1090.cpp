/*
 *create at 2018-07-25 09:38:25
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
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
        //freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    priority_queue<int, vector<int>, greater<int> > pq;
    int n, num;
    cin >> n;

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num);
    }

    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        sum += a + b;
        pq.push(a + b);
    }

    cout << sum << endl;

    return 0;
}