/*
 *create at 2018-07-23 21:30:55
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#ifndef ONLINE_JUDGE
    #define db(str, arg, ...) printf(str, arg, ##__VA_ARGS__);
#else
    #define db(str, arg, ...) ;
#endif
#define inf 0x3f3f3f3f
const int MAXN = 10005;

int book[25] = {0};
int map[25][25] = {0};
int lens[25] = {0};
char strs[25][100], ch;
int n, ans = 0;

int getCommon(int head, int tail) {
    int len1 = lens[head];
    int len2 = lens[tail];

    char *strHead = strs[head];
    char *strTail = strs[tail];

    for(int i = len1 - 1; i >= 0; i--) {
        if(strHead[i] == strTail[0]) {
            int j;
            for(j = 0; i + j < len1 && j < len2; j++) {
                if(strHead[i + j] != strTail[j])
                    break;
            }

            if(i + j == len1 && j != len2) {
                if(i != 0) return j;
            }
        }
    }
    return 0;
}

void dfs(int index, int m) {
    // printf("dfs %d, cur %d\n", index, m);
    // if(m > ans) printf("max!!\n");

    ans = max(ans, m);

    for(int i = 0; i < n; i++) {
        if(map[index][i] > 0 && book[i] < 2) {
            book[i]++;
            dfs(i, m + lens[i] - map[index][i]);
            book[i]--;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    while(scanf(" %d", &n) != EOF) {
        for(int i = 0; i < n; i++)
            scanf("%s", strs[i]);
        for(int i = 0; i < n; i++)
            lens[i] = strlen(strs[i]);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) 
                map[i][j] = getCommon(i, j);
        scanf(" %c", &ch);

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) 
        //         printf("%d ", map[i][j]);
        //     printf("\n");
        // }
        
        for(int i = 0; i < n; i++) {
            if(strs[i][0] == ch) {
                book[i]++;
                dfs(i, lens[i]);
                book[i]--;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}