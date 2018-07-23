/*
 *create at 2018-07-23 20:02:22
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

int order[MAXN];
struct Data {
    int id;
    int startPos;
    int endPos;
    char dir;
    int status; // 1 for Turning, 0 for dir
}s[MAXN];
int n, l, t;

bool cmpByStart(Data a, Data b) {
    return a.startPos < b.startPos;
}

bool cmpByEnd(Data a, Data b) {
    return a.endPos < b.endPos;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int cases;
    scanf("%d", &cases);
    for(int c = 1; c <= cases; c++) {
        printf("Case #%d:\n", c);

        scanf("%d %d %d", &l, &t, &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %c", &s[i].startPos, &s[i].dir);
            s[i].id = i;
            s[i].endPos = (s[i].dir == 'R' ? s[i].startPos + t : s[i].startPos - t);
            s[i].status = 0;
        }

        sort(s, s + n, cmpByStart);
        for(int i = 0; i < n; i++)
            order[s[i].id] = i;
        sort(s, s + n, cmpByEnd);
        for(int i = 0; i < n - 1; i++) {
            if(s[i].endPos == s[i + 1].endPos) {
                s[i].status = s[i + 1].status = 1;
            }
        }

        for(int i = 0; i < n; i++) {
            int temp = order[i];
            if(s[temp].endPos < 0 || s[temp].endPos > l) {
                printf("Fell off\n");
            } 
            else {
                if(s[temp].status == 1) {
                    printf("%d Turning\n", s[temp].endPos);
                }
                else {
                    printf("%d %c\n", s[temp].endPos, s[temp].dir);
                }
            }
        }
        printf("\n");
    }

    return 0;
}