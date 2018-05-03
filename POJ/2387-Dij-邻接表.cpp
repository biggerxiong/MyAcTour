/*
 *create at 2018-05-03 17:31:22
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
const int MAXN = 2005;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
};

struct Dij {
    int n, t;
    vector<Edge> edges;
    vector<int> g[MAXN];
    int book[MAXN];
    int f[MAXN];

    void init(int n) {
        this -> n = n;
        t = 0;
        for(int i = 1; i <= n; i++) 
            g[i].clear();
        edges.clear();
    }

    void addEdge(int u, int v, int w) {
        edges.push_back((Edge){u, v, w});
        edges.push_back((Edge){v, u, w});
        t += 2;
        g[u].push_back(t - 2);
        g[v].push_back(t - 1);
    }

    int dij() {
        memset(f, 0x3f, sizeof(f));
        memset(book, -1, sizeof(book));
        for(int i = 0; i < g[1].size(); i++) {
            Edge& e = edges[g[1][i]];
            f[e.v] = min(f[e.v], e.w);
        }
        // printf("start\n");
        // for(int i = 0; i < g[1].size(); i++)
        //     printf("%d ", g[1][i]);
        // printf("\nf:\n");
        // for(int i = 1; i <= n; i++)
        //     printf("%d ", f[i]);
        // printf("\n");
        book[1] = 0;
        for(int i = 0; i < n - 1; i++) {
            int minNum = inf, minIndex = 0;
            for(int j = 2; j <= n; j++) {
                if(book[j] && minNum > f[j]) {
                    minNum = f[j];
                    minIndex = j;
                }
            }
            book[minIndex] = 0;
            // printf("picck minIndex = %d, minNum = %d\n", minIndex, minNum);
            for(int j = 0; j < g[minIndex].size(); j++) {
                Edge& e = edges[g[minIndex][j]];
                f[e.v] = min(f[e.v], f[minIndex] + e.w);
            }
        }

        return f[n];
    }
};

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n, t, u, v, w;
    scanf("%d %d", &t, &n);
    Dij dij;
    dij.init(n);

    for(int i = 0; i < t; i++) {
        scanf("%d %d %d", &u, &v, &w);
        dij.addEdge(u, v, w);
    }

    printf("%d\n", dij.dij());
    return 0;
}