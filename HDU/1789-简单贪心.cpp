/*
 *create at 2018-09-10 14:18:35
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

struct Data {
    int time, score;
}a[1005];

bool cmp(Data a, Data b) {
    if(a.score != b.score)
        return a.score > b.score;
    return a.time > b.time;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int cases;
    cin >> cases;
    while(cases--) {
        int n;
        int book[1005];
        memset(book, -1, sizeof(book));

        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i].time;
        for(int i = 0; i < n; i++)
            cin >> a[i].score;

        sort(a, a + n, cmp);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            db("get time = %d, score = %d, book = %d\n", a[i].time, a[i].score, book[a[i].time]);
            if(book[a[i].time] == -1) 
                book[a[i].time] = a[i].score;
            else{
                int minIndex = a[i].time;
                for(int j = a[i].time - 1; j >= 1; j--) {
                    if(book[j] < book[minIndex])
                        minIndex = j;
                }
                db("get minIndex = %d, book[minIndex] = %d\n", minIndex, book[minIndex]);
                if(book[minIndex] > a[i].score) {
                    ans += a[i].score;
                    db("1ans + %d, now is %d\n", a[i].score, ans)
                }
                else if(book[minIndex] != -1) {
                    ans += book[minIndex];
                    db("2ans + %d, now is %d\n", book[minIndex], ans)
                    book[minIndex] = a[i].score;
                }
                else {
                    book[minIndex] = a[i].score;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}