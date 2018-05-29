/*
 *create at 2018-05-22 18:51:06
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
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

struct Tarjan {
    int low[MAXN], dfn[MAXN];
    bool inStack[MAXN];
    int n, index;
    stack<int> s;
    vector<int> G[MAXN];

    void init(int n) {
        memset(low, 0, sizeof(low));
        memset(dfn, 0, sizeof(dfn));
        memset(inStack, 0, sizeof(inStack));
        this -> n = n;
        index = 1;
        for(int i = 0; i <= n; i++)
            G[i].clear();
    }

    void addEdge(int u, int v) {
        G[u].push_back(v);
    }

    void solve(int u) {
        dfn[u] = low[u] = index++;
        s.push(u);
        inStack[u] = true;

        for(unsigned int i = 0; i < G[u].size(); i++) {
            int temp = G[u][i];
            if(dfn[temp] == 0) {
                solve(temp);
                low[u] = min(low[u], low[temp]);
            } else if(inStack[temp]) {
                low[u] = min(low[u], dfn[temp]);
            }
        }

        if(dfn[u] == low[u]) {
            int temp = s.top();
            while(temp != u) {
                printf("%d ", temp);
                s.pop();
                inStack[temp] = false;
                temp = s.top();
            }
            printf("%d\n", temp);
            s.pop();
            inStack[temp] = false;
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

    Tarjan tarjan;
    tarjan.init(n);
    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        tarjan.addEdge(u, v);
    }
    tarjan.solve(1);

    return 0;
}