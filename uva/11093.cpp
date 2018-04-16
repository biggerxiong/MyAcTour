/*
 *creat at 2018-04-16 19:48:47
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 100005

int p[MAXN], q[MAXN];
int n;

int solve() {
    int i, temp = 0, count = 0, ans = 0;
    for(i = 0; i < 2 * n; i++) {
        if(temp == 0)
            ans = i % n;

        temp += p[i % n];
        if(temp < q[i % n]) {
            temp = 0;
            count = 0;
        }
        else {
            temp -= q[i % n];
            count++;
            if(count == n) 
                return ans + 1;
        }
    }
    return -1;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    int cases, casesTemp = 0, i;
    cin >> cases;
    while(casesTemp++ < cases) {
        printf("Case %d: ", casesTemp);

        cin >> n;
        for(i = 0; i < n; i++) 
            scanf("%d", &p[i]);
        for(i = 0; i < n; i++) 
            scanf("%d", &q[i]);

        int ans = solve();
        if(ans == -1)
            printf("Not possible\n");
        else
            printf("Possible from station %d\n", ans);
    }

    return 0;
}