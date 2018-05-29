/*
 *creat at 2018-04-20 17:35:13
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 1005

int p[8][MAXN], ps = 0, plen[8], pcost[8];
int n, m, es, ans;
int f[MAXN];

struct Edge {
    int s, e;
    int val;
    Edge(){}
    Edge(int s, int e, int val): s(s), e(e), val(val) {}

    bool operator < (const Edge& rhs) const {
        return val < rhs.val;
    }
}edges[500005];
vector<Edge> orign;

struct Point {
    int x, y;
    Point(){}
    Point(int x, int y): x(x), y(y) {}

    int getdis(Point rhs) {
        return (int)((rhs.x - x) * (rhs.x - x) + (rhs.y - y) * (rhs.y - y));
    }
}points[MAXN];

void init() {
    for(int i = 0; i <= n; i++)
        f[i] = i;
}

int getf(int index) {
    return index == f[index] ? index : (f[index] = getf(f[index]));
}

void merge(int a, int b) {
    int x = getf(a);
    int y = getf(b);
    if(x != y) f[x] = y;
}

void input() {
    int i, j;
    scanf("%d %d", &n, &ps);
    for(i = 0; i < ps; i++) {
        scanf("%d %d", &plen[i], &pcost[i]);
        for(j = 0; j < plen[i]; j++) {
            scanf("%d", &p[i][j]);
            p[i][j] --;
        }
    }

    int x, y;
    for(i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        points[i] = Point(x, y);
    }
}

void getAllEdges() {
    int i, j;
    es = 0;
    for(i = 0; i < n; i++) 
        for(j = i + 1; j < n; j++) 
            edges[es++] = Edge(i, j, points[i].getdis(points[j]));
}

void getOriginEdges() {
    sort(edges, edges + es);
    init();

    int cnt = 0;
    for(int i = 0; i < es; i++) {
        if(getf(edges[i].s) != getf(edges[i].e)) {
            ans += edges[i].val;
            orign.push_back(edges[i]);
            merge(edges[i].s, edges[i].e);
            cnt++;
        }
        if(cnt == n - 1)
            break;
    }
}

void solve() {
    for(int seq = 0; seq < (1 << ps); seq++) {
        vector<Edge> v = orign;
        int sum = 0;
        // printf("\n");
        // for(auto it = v.begin(); it != v.end(); it++) 
        //     printf("%d ", it -> val);
        for(int j = 0; j < ps; j++) {
            if(seq & (1 << j)) {
                // printf("select %d\n", j);
                sum += pcost[j];
                for(int i = 1; i < plen[j]; i++) {
                    v.push_back(Edge(p[j][i - 1], p[j][i], 0));
                }
            }
        }
        // for(auto it = v.begin(); it != v.end(); it++) 
        //     printf("%d %d %d \n", it -> s, it -> e, it -> val);

        init();
        sort(v.begin(), v.end());
        int cnt = 0;
        for(auto it = v.begin(); it != v.end(); it++) {
            if(getf(it -> s) != getf(it -> e)) {
                sum += it -> val;
                merge(it -> s, it -> e);
                cnt ++;
            }
            if(cnt == n - 1)
                break;
        }
        // printf("sum = %d\n", sum);
        ans = min(ans, sum);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    int cases;
    scanf("%d", &cases);
    while(cases--) {
        input();
        getAllEdges();

        // first kruskal
        getOriginEdges();
        // for(auto it = orign.begin(); it != orign.end(); it++)
        //     cout << it->s << " " << it->e << " " << it->val << endl;
        
        // printf("p:\n");
        // for(int i = 0; i < ps; i++) {
        //     for(int j = 0; j < plen[i]; j++) {
        //         printf("%d ", p[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("ans = %d\n", ans);
        ans = inf;
        solve();
        printf("%d\n", ans);
        if(cases)
            printf("\n");
    }

    return 0;
}