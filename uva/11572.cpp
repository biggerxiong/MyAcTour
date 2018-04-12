/*
 *creat at 2018-04-12 13:52:43
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
#define MAXN 1000005

int a[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int cases;
    int n, i, ans, ansTemp;
    set <int> s;

    scanf("%d", &cases);
    while(cases--) {
        s.clear();
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            // printf("%d ", a[i]);
        }
        // printf("\n");

        ans = ansTemp = 0;
        int head = 0, tail = 0;
        for(i = 0; i < n; i++, tail++) {
            if(!s.count(a[i])) {
                s.insert(a[i]);
                ansTemp++;
                // printf("ansTemp++, now is %d\n", ansTemp);
            }
            else {
                ansTemp++;
                // printf("get %d, start remove\n", a[i]);
                for(; ; head++) {
                    s.erase(a[head]);
                    ansTemp--;
                    // printf("ansTemp--, now is %d\n", ansTemp);

                    // printf("remove %d\n", a[head]);
                    if(a[head] == a[i]) {
                        head++;
                        s.insert(a[i]);
                        break;
                    }
                }
            }

            ans = max(ans, ansTemp);
        }
        printf("%d\n", ans);
    }

    return 0;
}