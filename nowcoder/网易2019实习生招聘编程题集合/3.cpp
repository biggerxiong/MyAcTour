/*
 *creat at 2018-04-23 19:24:14
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 1005

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    int cases;
    int n;
    char str[MAXN];

    cin >> cases;
    while(cases--) {
        scanf(" %d %s", &n, str);

        int ans = 0;
        for(int i = 0; i < n;) {
            // printf("i = %d, str[i] = %c\n", i, str[i]);
            if(str[i] == '.') {
                // printf("i = %d, ans++\n", i);
                if(n - i >= 3) {
                    // if((str[i + 1] == 'X' && str[i + 2] == '.') ||
                    //     (str[i + 1] == '.' && str[i + 2] == 'X') || 
                    //     (str[i + 1] == 'X' && str[i + 2] == 'X')) {
                        i += 3;
                    // }
                }
                else {
                    ans++;
                    break;
                }
                // else if(n - i == 2)
                ans++;
            }
            else
                i++;
        }
        printf("%d\n", ans);
    }

    return 0;
}