/*
 *creat at 2018-04-12 18:05:21
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 1000005

int n, a[MAXN], last[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    int cases, i;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &n);
        map<int, int> cur;
        for(i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
                // printf("%d ", a[i]);
            if(!cur.count(a[i]))
                last[i] = -1;
            else
                last[i] = cur[a[i]];

            cur[a[i]] = i;
        }
        // printf("\n");

        int head = 0;
        int ans, ansTemp = ans = 0;
        for(i = 0; i < n; i++) {
            if(last[i] >= head) {
                head = last[i] + 1;
                ansTemp = i - head + 1;
                // printf("cur is %d, head = %d, ansTemp = %d\n", a[i], head, ansTemp);
            }
            else {
                ansTemp++;
                // printf("cur is %d, ansTemp++ = %d\n", a[i], ansTemp);
            }
            ans = max(ans, ansTemp);
        }

        printf("%d\n", ans);
    }

    return 0;
}