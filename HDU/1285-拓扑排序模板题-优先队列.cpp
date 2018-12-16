/*
 *create at 2018-12-09 09:52:56
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;
#ifndef ONLINE_JUDGE
    #define db(str, arg, ...) printf(str, arg, ##__VA_ARGS__);
#else
    #define db(str, arg, ...) ;
#endif
#define inf 0x3f3f3f3f
const int MAXN = 505;

int map[MAXN][MAXN];
int in[MAXN];

struct Data {
    int val;
    bool operator< (const Data& rhs) const {
        return val > rhs.val;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        // freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif
    
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int a, b;
        memset(map, 0, sizeof(map));
        memset(in, 0, sizeof(in));

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            if (map[a][b] == 0) {
                map[a][b] = 1;
                in[b]++;
            }
        }

        priority_queue<Data> pq;
        Data temp;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                temp.val = i;
                pq.push(temp);
            }
        }

        int cnt = 1;
        while (!pq.empty()) {
            temp = pq.top();
            pq.pop();

            if (cnt != 1)
                printf(" ");
            int cur = temp.val;
            printf("%d", cur);
            cnt++;
            
            for (int i = 1; i <= n; i++) {
                if (map[cur][i] == 1) {
                    in[i]--;
                    if (in[i] == 0) {
                        temp.val = i;
                        pq.push(temp);
                    }
                }
            }
        }

        printf("\n");
    }

    return 0;
}
