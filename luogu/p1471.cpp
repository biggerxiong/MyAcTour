/*
 *create at 2018-05-21 09:14:16
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
const int MAXN = 200005;
const double exps = 1e-6;
#define lchirld (root*2+1)
#define rchirld (root*2+2)

bool isZero(double num) {
    return fabs(num) <= exps;
}

struct SegmentTree {
    double sum;
    double sum2;
    double addmark;
}st[MAXN * 2 + 1];

void build(int root, int start, int end) {
    if(start == end) {
        scanf("%lf", &st[root].sum);
        st[root].sum2 = st[root].sum * st[root].sum;
        st[root].addmark = 0;
        return;
    }

    int mid = (start + end) / 2;
    build(lchirld, start, mid);
    build(rchirld, mid + 1, end);

    st[root].sum = st[lchirld].sum + st[rchirld].sum;
    st[root].sum2 = st[lchirld].sum2 + st[rchirld].sum2;
}

void pushDown(int root, int start, int end) {
    if(isZero(st[root].addmark))
        return;

    int mid = (start + end) / 2;
    int lcount = mid - start + 1; // 左边的包括mid，所以+1
    int rcount = end - mid; // 右边的不包括mid，不+1
 
    double m = st[root].addmark;
    st[lchirld].sum2 += lcount * m * m + 2 * m * st[lchirld].sum;
    st[rchirld].sum2 += rcount * m * m + 2 * m * st[rchirld].sum;

    st[lchirld].sum += (lcount) * m;
    st[rchirld].sum += (rcount) * m;

    st[lchirld].addmark += m;
    st[rchirld].addmark += m;

    st[root].addmark = 0;
}

void update(int root, int start, int end, int ustart, int uend, double val) {
    if(start > uend || end < ustart)
        return;

    if(start >= ustart && end <= uend) {
        st[root].addmark += val;
        st[root].sum2 += (end - start + 1) * val * val + 2 * val * st[root].sum;
        st[root].sum += (end - start + 1) * val;
        return;
    }

    pushDown(root, start, end);
    int mid = (start + end) / 2;
    update(lchirld, start, mid, ustart, uend, val);
    update(rchirld, mid + 1, end, ustart, uend, val);

    st[root].sum = st[lchirld].sum + st[rchirld].sum;
    st[root].sum2 = st[lchirld].sum2 + st[rchirld].sum2;
}

double querySum(int root, int start, int end, int qstart, int qend) {
    if(start > qend || end < qstart)
        return 0;

    if(start >= qstart && end <= qend) 
        return st[root].sum;

    pushDown(root, start, end);
    int mid = (start + end) / 2;
    return querySum(lchirld, start, mid, qstart, qend) + querySum(rchirld, mid + 1, end, qstart, qend);
}

double querySum2(int root, int start, int end, int qstart, int qend) {
    if(start > qend || end < qstart)
        return 0;

    if(start >= qstart && end <= qend) 
        return st[root].sum2;

    pushDown(root, start, end);
    int mid = (start + end) / 2;
    return querySum2(lchirld, start, mid, qstart, qend) + querySum2(rchirld, mid + 1, end, qstart, qend);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);
    build(0, 0, n - 1);

    int op, a, b;
    double val;
    while(m--) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d %d %lf", &a, &b, &val);
            a--; b--;
            update(0, 0, n - 1, a, b, val);
        } else if(op == 2) {
            scanf("%d %d", &a, &b);
            a--; b--;
            printf("%.4lf\n", querySum(0, 0, n - 1, a, b) / (b - a + 1));
        } else if(op == 3) {
            scanf("%d %d", &a, &b);
            a--; b--;
            double s = querySum(0, 0, n - 1, a, b);
            int count = b - a + 1;
            double avg = s / count;
            printf("%.4lf\n", querySum2(0, 0, n - 1, a, b) / count - avg * avg);
        }
    }

    return 0;
}