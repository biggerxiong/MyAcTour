/*
 *create at 2018-05-14 09:03:02
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f
const int MAXN = 305;

/*
采用邻接矩阵存储
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
*/

int g[MAXN][MAXN];
int pre[MAXN];
bool done[MAXN];
int s, e;
int n, m;

int EK() {
    memset(done, 0, sizeof(done));
    memset(pre, 0, sizeof(pre));

    queue<int> q;
    q.push(s);
    pre[s] = 0;
    done[s] = 1;
    bool hasMinFlow = false;
    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int i = 1; i <= n; i++) {
            if(g[u][i] && !done[i]) {
                pre[i] = u;
                if(i == e) {
                    hasMinFlow = true;
                    break;
                }
                else {
                    done[i] = true;
                    q.push(i);
                }
            }
        }
        if(hasMinFlow) break;
    }
    if(!hasMinFlow) return 0;

    int u = e, minFlow = inf;
    while(pre[u]) {
        minFlow = min(minFlow, g[pre[u]][u]);
        u = pre[u];
    }

    u = e;
    while(pre[u]) {
        g[pre[u]][u] -= minFlow;
        g[u][pre[u]] += minFlow;
        u = pre[u];
    }
    return minFlow;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int u, v, w;
    while(scanf("%d %d", &m, &n) != EOF) {
        memset(g, 0, sizeof(g));
        s = 1, e = n;
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            g[u][v] += w;
        }

        int curFlow = inf, ans = 0;
        while(curFlow = EK()) {
            ans += curFlow;
        }
        printf("%d\n", ans);
    }

    return 0;
}