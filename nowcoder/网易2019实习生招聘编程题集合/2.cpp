/*
 *creat at 2018-04-23 18:13:00
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

int temp[10] = {0, 0, 1};
int getAns(int n) {
    return (n / 3 * 2) + (temp[n % 3]);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    // int i, j = 1, all = 0;
    // int l, r, ansl, ansr;
    // int sum = 0;

    // for(i = 1; i <= r; i++, j++) {
    //     printf("i = %d  ", i);
    //     sum += j;
    //     if(sum % 3 == 0) {
    //         printf("1\n");
    //         all ++;
    //     }
    //     else
    //         printf("0\n");
    //     sum %= 3;
    // }

    int l, r;

    cin >> l >> r;

    // int ansl = getAns(l - 1);
    // int ansr = getAns(r);

    // printf("%d %d\n", ansl, ansr);
    cout << getAns(r) - getAns(l - 1) << endl;

    return 0;
}