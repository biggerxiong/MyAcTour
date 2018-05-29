/*
 *create at 2018-05-19 16:29:41
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

struct Topu {
    int in[MAXN], n;
    vector<int> G[MAXN];
    vector<int> ans;

    void init(int n) {
        for(int i = 0; i < MAXN; i++) 
            G[i].clear();
        ans.clear();
        memset(in, 0, sizeof(in));
        this -> n = n;
    }

    void addEdge(int before, int after) {
        G[before].push_back(after);
        in[after]++;
    }

    void solve() {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 1; i <= n; i++) {
            if(in[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int u = q.top(); q.pop();
            ans.push_back(u);

            for(int i = 0; i < G[u].size(); i++) {
                in[G[u][i]]--;
                if(in[G[u][i]] == 0) {
                    q.push(G[u][i]);
                }
            }
        }

        for(int i = 0; i < ans.size(); i++) {
            printf("%d ", ans[i]);
        }
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);

    int a, b;
    Topu topu;
    topu.init(n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        topu.addEdge(a, b);
    }

    topu.solve();

    return 0;
}