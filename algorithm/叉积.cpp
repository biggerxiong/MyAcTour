/*
 *create at 2018-05-17 16:36:20
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
    #define db(str, arg, ...) printf(str, arg, ##s__VA_ARGS__);
#else
    #define db(str, arg, ...) ;
#endif
#define inf 0x3f3f3f3f
const double eps = 1e-8;
const int MAXN = 10005;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}

    const bool operator() (Point& rhs) const {
        if(x != rhs.x) return false;
        else return y == rhs.y;
    }

    const bool operator< (Point& rhs) const {
        if(x != rhs.x) return x < rhs.x;
        else return y < rhs.y;
    }
};

struct Vec {
    Point start, end;
    double x, y;
    Vec(Point a, Point b):start(a), end(b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

double cross(Vec a, Vec b) {
    return a.x * b.y - a.y * b.x;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    Point a(1, -1), b(0, 4), c(2, 0);
    Vec ab(c, a), ac(c, b);
    printf("%lf\n", cross(ab, ac));

    return 0;
}