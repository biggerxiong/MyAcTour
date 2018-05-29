/*
 *create at 2018-05-16 14:26:33
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f
const int MAXN = 10005;

struct Edge {
    int from, to, val;
    Edge(int from, int to, int val): from(from), to(to), val(val) {}
};

struct BFS {
    vector<Edge> edges;
    bool done[MAXN];
    vector<int> G[MAXN], ans;
    int n, t, pre[MAXN];

    void init(int n) {
        this->n = n;
        t = 0;
        edges.clear();
        for(int i = 0; i <= n; i++) {
            G[i].clear();
        }
        memset(done, 0, sizeof(done));
        memset(pre, 0, sizeof(pre));
    }

    void addEdge(int u, int v, int w) {
        // edges.push_back((Edge){u, v, w});
        // edges.push_back((Edge){v, u, w});
        // t += 2;
        // G[u].push_back(t - 2);
        // G[v].push_back(t - 1);
        edges.push_back((Edge){u, v, w});
        t++;
        G[u].push_back(t - 1);
    }

    void printEdge() {
        for(int i = 0; i < edges.size(); i++) {
            printf("%d %d %d\n", edges[i].from, edges[i].to, edges[i].val);
        }
    }

    void solve() {
        queue<int> q;
        q.push(1);
        done[1] = true;

        bool hasAns = false;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            // printf("u = %d\n", u);
            for(int i = 0; i < G[u].size(); i++) {
                Edge e = edges[G[u][i]];
                // printf("get %d ", e.to);
                if(!done[e.to]) {
                    // printf("push\n");
                    q.push(e.to);
                    done[e.to] = true;
                    pre[e.to] = u;
                }
                else {
                    // printf("is ans\n");
                    hasAns = true;
                    ans.push_back(e.to);
                    int p = u, temp = p;
                    int endIndex = 0;
                    vector<int> ansTemp;
                    while(p) {
                        // ans.push_back(p);
                        ansTemp.push_back(p);
                        p = pre[p];
                        pre[temp] = 0;
                        // printf("pretemp=0, where temp = %d\n", temp);
                        temp = p;
                    }
                    p = pre[e.to]; temp = p;
                    while(p) {
                        ans.push_back(p);
                        p = pre[p];
                        pre[temp] = 0;
                        // printf("pretemp=0, where temp = %d\n", temp);
                        if(p != 0) temp = p;
                    }
                    endIndex = temp;

                    for(int i = 0; i < ansTemp.size(); i++) {
                        if(ansTemp[i] == endIndex)
                            break;
                        else
                            ans.push_back(ansTemp[i]);
                    }
                    break;
                }
            }

           if(hasAns) break;
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        for(int i = 0; i < ans.size(); i++)
           printf("%d ", ans[i]);
    }
};

int main () {
    #ifndef ONLINE_JUDGE 
        freopen("input2.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n, a, b;
    scanf("%d", &n);
    BFS bfs;
    bfs.init(n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        bfs.addEdge(a, b, 0);
    }
    // bfs.printEdge();
    bfs.solve();

    return 0;
}
