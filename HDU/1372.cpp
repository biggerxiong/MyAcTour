/*
 *create at 2018-12-08 22:45:15
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
const int MAXN = 10;

struct Data {
    int x, y;
    int step;
};

int map[MAXN][MAXN];
int book[MAXN][MAXN];
int startx, starty, endx, endy;
int front, tail;
int dir[8][2]={-1,-2,1,-2,-1,2,1,2,-2,1,-2,-1,2,1,2,-1};

bool check(int x, int y) {
    if (x < 1 || y < 1 || x > 8 || y > 8)
        return false;
    if (book[x][y] == 1)
        return false;
    return true;
}

int bfs() {
    Data s, queue[MAXN * MAXN];
    memset(book, 0, sizeof(book));
    s.x = startx, s.y = starty, s.step = 0;
    front = tail = 0;
    queue[tail++] = s;
    book[startx][starty] = 1;

    while (front < tail) {
        Data temp = queue[front++];
        if (temp.x == endx && temp.y == endy)
            return temp.step;

        for (int i = 0; i < 8; i++) {
            int nx = temp.x + dir[i][0];
            int ny = temp.y + dir[i][1];

            if (check(nx, ny)) {
                // db("add %d %d to queue\n", nx, ny);
                book[nx][ny] = 1;
                Data t;
                t.x = nx, t.y = ny, t.step = temp.step + 1;
                queue[tail++] = t;
            }
        }
    }
    return -1;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    char tempa, tempb;
    while (scanf(" %c%d %c%d", &tempa, &starty, &tempb, &endy) != EOF) {
        startx = tempa - 'a' + 1;
        endx = tempb - 'a' + 1;

        // db("startx = %d, starty = %d, endx = %d, endy = %d\n", startx, starty, endx, endy);
        printf("To get from %c%d to %c%d takes %d knight moves.\n", tempa, starty, tempb, endy, bfs());
    }

    return 0;
}