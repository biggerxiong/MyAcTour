/*
 *creat at 2018-03-24 10:52:56
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

int main () {
    char str[1005];
    int num[1005], index, i;

    while (scanf(" %s", str) != EOF) {
        index = 0;
        int temp = 0;
        for (i = 0; str[i] != '\0'; i++) {
            if (str[i] != '5') {
                temp *= 10;
                temp += str[i] - '0';
            }
            else {
                if (i > 0 && str[i - 1] != '5') {
                    // printf("at %d put %d\n", i, temp);
                    num[index++] = temp;
                    temp = 0;
                }
            }
        }
        if (str[i - 1] != '5')
            num[index++] = temp;

        sort(num, num + index);

        printf("%d", num[0]);
        for (i = 1; i < index; i++) {
            printf(" %d", num[i]);
        }
        printf("\n");
    }
}
