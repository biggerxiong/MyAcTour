/*
 *creat at 2018-04-13 19:19:27
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 10005

long long cases, n, m;
long long a[MAXN]; // 存放数据
bool vis[MAXN]; // vis[i] 为true代表 i 下标的这个数输出后，要接着输出一个 '/'

long long check(long long maxNum) {
    memset(vis, 0, sizeof(vis));

    long long i, count = 1, sum = 0;
    for(i = n - 1; i >= 0; i--) {
        if(sum + a[i] > maxNum) {
            count++;
            vis[i] = 1;
            sum = a[i];
        }
        else
            sum += a[i];

        if(count > m)
            return -1;

        if(m - count == i && i != 0) {
            // 如果剩下的数字和剩余要划分的个数相等，就每个数字划一个
            while(i--) {
                if(a[i] > maxNum) // 这里之前没有判断，wa了一发
                    return -1;
                vis[i] = true;
            }
            return 1;
        }
    }
    return 1;
}

void print(long long maxNum) {
    check(maxNum); // 更新vis数组

    for(int i = 0; i < n; i++) {
        if(i) printf(" ");
        printf("%lld", a[i]);
        if(vis[i]) printf(" /");
    }
    printf("\n");
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    long long i, sum, ans, head, tail, mid, temp;
    scanf("%lld", &cases);
    while(cases--) {
        scanf("%lld %lld", &n, &m);
        sum = 0;
        for(i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            sum += a[i];
        }

        ans = sum;
        head = 0; tail = sum;
        mid = (head + tail) / 2;
        while(head < tail - 1) {
            temp = check(mid);
            // printf("mid = %d, head = %d, tail = %d,temp = %d\n", mid, head, tail, temp);
            if(temp < 0) {
                head = mid;
            }
            else if (temp > 0) {
                ans = mid;
                tail = mid;
            }
            mid = (head + tail) / 2;
        }

        print(ans);
    }
    return 0;
}