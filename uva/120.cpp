/*
 *creat at 2018-04-11 17:38:42
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornr(i, n) for(int i = n - 1; i >= 0; i--)

int a[35], n, tal;

bool check() {
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i - 1])
            return false;
    }
    return true;
}

void reverse(int k) {
    for(int i = 0; i <= (n - k) / 2; i++) {
        // printf("swap %d %d\n", i, n - k - i - 1);
        swap(a[i], a[n - k - i]);
    }

    // printf("\nreverse %d, now is :", k);
    // for(int i = 0; i < n; i++)
    //     printf("%d ", a[i]);
    // printf("\n");
}

int main () {
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    char ch;
    while(scanf("%d", &a[0]) != EOF) {
        n = 1;

        ch = getchar();
        if(ch == '\n') {
            printf("%d\n%d\n", a[0], 0);
            continue;
        }

        while(scanf("%d", &a[n++])) {
            ch = getchar();
            if(ch == '\n') {
                break;
            }
        }

        printf("%d", a[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", a[i]);
        printf("\n");

        tal = 0;
        for(int i = 0; i < n; i++) {
            if(!check()) {
                int maxIndex = max_element(a, a + n - tal) - a;
                // printf("maxIndex is %d\n", maxIndex);
                if(maxIndex != 0) {
                    printf("%d ", n - maxIndex);
                    reverse(n - maxIndex);
                }

                printf("%d ", tal + 1);
                reverse(tal + 1);
                tal++;
            }
            else {
                printf("0\n");
                break;
            }
        }

    }

    return 0;
}