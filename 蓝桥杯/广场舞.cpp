/*
 *create at 2018-05-17 16:36:20
 *author: XiongXuan
 */
// #include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

#ifndef ONLINE_JUDGE
    #define db(str, arg, ...) printf(str, arg, ##__VA_ARGS__);
#else
    #define db(str, arg, ...) ;
#endif
#define inf 0x3f3f3f3f
const double eps = 1e-8;
const int MAXN = 10005;
struct Point {
    int x, y;
    Point(int x = 0, int y = 0): x(x), y(y) {}

    bool operator< (const Point& rhs) const {
        if(x != rhs.x) return x < rhs.x;
        else return y < rhs.y;
    }
};

struct Vec {
    Point start, end;
    int x, y;
    Vec(Point a, Point b):start(a), end(b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

int cross(Vec a, Vec b) {
    return a.x * b.y - a.y * b.x;
}

map<Point, bool> pstatus;
vector<Point> points;
vector<Vec> vecs;
long long ans = 0;

bool isRight(Point p, Vec v) {
    Vec nv(v.start, p);
    return v.x * nv.y - v.y * nv.x <= 0;
}

bool isIn(int x, int y) {
    Point p(x, y);
    if(pstatus.count(p) != 0)
        return pstatus[p];

    for(int i = 0; i < vecs.size(); i++) {
        if(!isRight(p, vecs[i])) {
            db("fails i = %d\n", i);
            return pstatus[p] = false;
        }
    }
    return pstatus[p] = true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n, tempx, tempy, minx = inf, maxx = -inf, miny = inf, maxy = -inf;
    scanf("%d", &n);

    scanf("%d %d", &tempx, &tempy);
    minx = maxx = tempx;
    miny = maxy = tempy;
    Point lastPoint(tempx, tempy);
    n--;

    while(n--) {
        scanf("%d %d", &tempx, &tempy);
        minx = min(minx, tempx);
        maxx = max(maxx, tempx);
        miny = min(miny, tempy);
        maxy = max(maxy, tempy);

        vecs.push_back((Vec) {lastPoint, (Point) {tempx, tempy}});
        lastPoint.x = tempx;
        lastPoint.y = tempy;
    }

    for(int i = minx; i < maxx - 1; i++) {
        for(int j = miny; j < maxy - 1; j++) {
            if(printf("i = %d, j = %d", i, j) && isIn(i, j) && printf(" 1 ") 
                && isIn(i + 1, j) && printf("2 ") 
                && isIn(i, j + 1) && printf("3 ") 
                && isIn(i + 1, j + 1) && printf("4 ")) {
                ans++;
                printf("(%d, %d)\n", i, j);
            }
            printf("\n");
        }
    }

    printf("%lld\n", ans);

    printf("\n\n\n");
    pstatus.erase((Point){2, 3});
    cout << isIn(2, 3);
    return 0;
}