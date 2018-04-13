/*
 *creat at 2018-04-13 17:27:10
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 100005

int cases, n, l;
int s[MAXN];
deque <int> q;

int great(int r, int x, int y, int z) {
    // 返回正数代表后面的斜率比前面的大
    return (s[z] - s[y]) * (x - r) - (s[x] - s[r]) * (z - y);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int i, j;
    char ch;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d %d", &n, &l);
        getchar();
        s[0] = 0;
        for(i = 1; i <= n; i++) {
            ch = getchar();
            s[i] = s[i - 1] + ch - '0';
        }

        int t, t1, t2;
        int ansl = 0, ansr = l;
        q.clear();
        for(i = l; i <= n; i++) {
            j = i - l;
            while(q.size() > 1) {
                t1 = q[q.size() - 1];
                t2 = q[q.size() - 2];
                if(great(t2, t1, t1, j) <= 0)
                    q.pop_back();
                else
                    break;
            }

            q.push_back(j);

            while(q.size() > 1) {
                t1 = q[0];
                t2 = q[1];
                if(great(t1, i, t2, i) >= 0)
                    q.pop_front();
                else
                    break;
            }

            t1 = q[0];
            t = great(t1, i, ansl, ansr);
            if(t < 0 || (t == 0 && i - t1 < ansr - ansl)) {
                ansr = i;
                ansl = t1;
            }
        }

        printf("%d %d\n", ansl + 1, ansr);
    }
    return 0;
}