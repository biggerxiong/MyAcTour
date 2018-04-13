/*
 *creat at 2018-04-12 20:08:23
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 200005

int a[MAXN], n;
int f[MAXN], g[MAXN];

struct Data {
    int a, g;
    Data(int a, int g):a(a), g(g) {}
    bool operator < (const Data& o) const {
        return a < o.a;
    }
};
set <Data> s;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int cases;
    int i;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        g[0] = 1;
        for(i = 1; i < n; i++) {
            if(a[i] > a[i - 1])
                g[i] = g[i - 1] + 1;
            else
                g[i] = 1;
        }
        // printf("g:");
        // for(i = 0; i < n; i++) 
        //     printf("%d ", g[i]);
        // printf("\n");

        f[n - 1] = 1;
        for(i = n - 2; i >= 0; i--) {
            if(a[i] < a[i + 1])
                f[i] = f[i + 1] + 1;
            else
                f[i] = 1;
        }
        // printf("f:");
        // for(i = 0; i < n; i++) 
        //     printf("%d ", f[i]);
        // printf("\n");

        s.clear();
        s.insert(Data(a[0], g[0]));
        int ans, ansTemp = ans = 1;
        for(i = 1; i < n; i++) {
            Data d(a[i], g[i]);
            auto it = s.lower_bound(d);
            bool keep = true;
            if(it != s.begin()) {
                it--;
                ansTemp = it -> g + f[i];
                ans = max(ansTemp, ans);

                if(g[i] <= it -> g)
                    keep = false;
            }
            if(keep) {
                s.erase(d);
                s.insert(d);
                it = s.find(d);
                it++;
                while(it != s.end() && d.a < it -> a && d.g >= it -> g) {
                    s.erase(it);
                    it++;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}