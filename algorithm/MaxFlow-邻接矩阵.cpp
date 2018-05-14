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
const int MAXN = 10005;

/*
采用邻接矩阵存储
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
*/

int G[MAXN][MAXN] = {0};
int m, n;
int pre[MAXN];
bool done[MAXN];

int EK() {
    memset(done, 0, sizeof(done));
    memset(pre, 0, sizeof(pre));

    queue<int> q;
    q.push(1);
    done[1] = true;
    bool hasMinFlow = false;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i = 1; i <= n; i++) {
            if(G[u][i] && !done[i]) {
                pre[i] = u;
                if(i == n) {
                    hasMinFlow = true;
                    break;
                }
                else {
                    q.push(i);
                    done[i] = true;
                }
            }
        }
        if(hasMinFlow == true) break;
    }
    if(hasMinFlow == false) return 0;

    int minVal = inf;
    int v = n;
    while(pre[v]) {
        minVal = min(minVal, G[pre[v]][v]);
        v = pre[v];
    }

    v = n;
    while(pre[v]) {
        G[pre[v]][v] -= minVal;
        G[v][pre[v]] += minVal;
        v = pre[v];
    }

    return minVal;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int u, v, w;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u][v] += w;
    }

    int curFlow, ans = 0;
    while(curFlow = EK()) {
        ans += curFlow;
    }
    printf("%d\n", ans);

    return 0;
}