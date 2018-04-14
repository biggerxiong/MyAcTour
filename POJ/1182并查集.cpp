/*
 *creat at 2018-04-14 12:45:07
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 50005

int frend[MAXN], eat[MAXN];
int n, k;

int getf(int *arr, int index) {
    if(arr[index] == index)
        return index;
    return arr[index] = getf(arr, arr[index]);
}

void merge(int *arr, int a, int b) {
    int x = getf(arr, a);
    int y = getf(arr, b);

    if(arr[x] != y)
        arr[x] = y;
}

void init() {
    for(int i = 0; i <= n; i++) {
        frend[i] = i;
        eat[i] = i;
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    scanf("%d %d", &n, &k);
    int op, x, y, ans = 0;
    int rootx, rooty;
    init();
    while(k--){
        scanf("%d %d %d", &op, &x, &y);
        // printf("get op = %d, x = %d, y = %d\n", op, x, y);
        if(x > n || y > n) {
            // printf("1 ans++\n");
            ans++;
        }
        else if(op == 2 && x == y) {
            // printf("2 ans++\n");
            ans++;
        }
        else {
            rootx = getf(frend, x);
            rooty = getf(frend, y);
            // printf("eat rootx = %d, eat rooty = %d\n", eat[rootx], eat[rooty]);

            if(op == 1) { // 如果两方是同类
                if(eat[rootx] == rooty || eat[rooty] == rootx) {
                    // 其中一方吃另一方
                    if(eat[rootx] != rootx || eat[rooty] != rooty) {
                        // printf("3 ans++\n");
                        ans++;
                    }
                }
                else if(eat[eat[rootx]] == rooty) {
                    // x 吃 t, t 吃 y, 那么x 和 y是同类，是假话
                    // printf("6 ans++\n");
                    ans++;
                }
                else
                    merge(frend, x, y);
            }
            else { // 如果是x吃y
                if(rootx == rooty) {
                    // 两方是同类
                    // printf("4 ans++\n");
                    ans++;
                }
                else if(eat[rooty] == rootx) {
                    // 事实是y吃x
                    // printf("5 ans++\n");
                    ans++;
                }
                else {
                    eat[rootx] = rooty;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}