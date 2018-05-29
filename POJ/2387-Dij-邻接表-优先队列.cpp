/*
 *create at 2018-05-03 20:15:32
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
const int MAXN = 2005;

struct Edge {
    int from, to, dist;
    Edge(int u, int v, int w): from(u), to(v), dist(w) {}
};

struct HeapNode {
    int dist, to;
    HeapNode(int dist, int to): dist(dist), to(to) {};

    bool operator< (const HeapNode& rhs) const {
        return dist > rhs.dist;
    }
};

struct Dij {
    int n, t;
    int start, end;
    vector<Edge> edges;
    vector<int> g[MAXN];
    int done[MAXN], f[MAXN];

    void init(int n, int start, int end) {
        this -> n = n;
        this -> start = start;
        this -> end = end;
        this -> t = 0;

        edges.clear();
        for(int i = 0; i <= n; i++) 
            g[i].clear();
        memset(done, 0, sizeof(done));
        memset(f, 0x3f, sizeof(f));
    }

    void addEdge(int from, int to, int dist) {
        edges.push_back((Edge) {from, to, dist});
        edges.push_back((Edge) {to, from, dist});
        t += 2;
        g[from].push_back(t - 2);
        g[to].push_back(t - 1);
    }

    void print() {
        // for(int i = 0; i < edges.size(); i++) 
        //     printf("%d %d %d\n", edges[i].from, edges[i].to, edges[i].dist);

        for(int i = 1; i <= n; i++) {
            printf("%d:", i);
            for(int j = 0; j < g[i].size(); j++) 
                printf("%d-%d ", edges[g[i][j]].to, edges[g[i][j]].dist);
            printf("\n");
        }
    }

    int dij() {
        priority_queue<HeapNode> pq;
        f[start] = 0;
        pq.push((HeapNode) {0, start});
        while(!pq.empty()) {
            HeapNode node = pq.top(); pq.pop();
            if(done[node.to]) continue;
            done[node.to] = true;

            // printf("use %d %d\n", node.dist, node.to);

            int to = node.to;
            for(int i = 0; i < g[to].size(); i++) {
                Edge& e = edges[g[to][i]];
                if(f[e.to] > f[to] + e.dist) {
                    // printf("e.to=%d, to=%d\n", e.to, to);
                    // printf("feto=%d, fto=%d, node.dist=%d\n", f[e.to], f[to], node.dist);
                    f[e.to] = f[to] + e.dist;
                    pq.push((HeapNode) {f[e.to], e.to});
                }
            }
        }
        return f[end];
    }
};

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n, t;
    cin >> t >> n;
    Dij dij;
    dij.init(n, 1, n);

    int u, v, w;
    for(int i = 0; i < t; i++) {
        scanf("%d %d %d", &u, &v, &w);
        dij.addEdge(u, v, w);
    }
    // dij.print();
    printf("%d\n", dij.dij());

    return 0;
}