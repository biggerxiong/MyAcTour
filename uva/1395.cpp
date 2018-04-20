/*
 *creat at 2018-04-20 17:12:52
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 105

int f[MAXN];

int getf(int index) {
    return f[index] == index ? index : (f[index] = getf(f[index]));
}

void merge(int a, int b) {
    int x = getf(a);
    int y = getf(b);
    if(x != y)
        f[x] = y;
}

void init() {
    for(int i = 1; i <= MAXN; i++)
        f[i] = i;
}

struct Edge {
    int s, e, val;

    bool operator < (const Edge& rhs) const {
        return val < rhs.val;
    }
}s[5005];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    int i, n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        if(n == 0 && m == 0)
            break;

        Edge temp;
        for(i = 0; i < m; i++) {
            scanf("%d %d %d", &temp.s, &temp.e, &temp.val);
            s[i] = temp;
        }
        sort(s, s + m);

        int l, r, cnt, ans = inf;
        for(l = 0; l <= m - n + 1; l++) {
            cnt = 0;
            init();
            for(r = l; r < m; r++) {
                if(getf(s[r].s) != getf(s[r].e)) {
                    merge(s[r].s, s[r].e);
                    cnt++;
                }
                if(cnt == n - 1) {
                    ans = min(ans, s[r].val - s[l].val);
                    break;
                }
            }
        }
        printf("%d\n", ans == inf ? -1 : ans);
    }
    return 0;
}