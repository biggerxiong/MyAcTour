/*
 *creat at 2018-04-23 17:36:54
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 1000000000

struct Data {
    int d, p;
    Data(){}
    Data(int d, int p): d(d), p(p) {}

    bool operator < (const Data& rhs) const {
        if(d != rhs.d)
            return d < rhs.d;
        return p > rhs.p;
    }
};

int main () {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    int n, m, tempd, tempp, i, j;
    vector<Data> v;
    vector<int> preSum;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++) {
        scanf("%d %d", &tempd, &tempp);
        v.push_back(Data(tempd, tempp));
    }

    sort(v.begin(), v.end());


    int maxNum = -1;
    for(auto it = v.begin(); it != v.end(); it++) {
        maxNum = max(it -> p, maxNum);
        preSum.push_back(maxNum);
    }

    for(i = 0; i < m; i++) {
        scanf("%d", &j);

        auto it = lower_bound(v.begin(), v.end(), Data(j, MAXN));
        if(it -> d <= j)
            printf("%d\n", preSum[it - v.begin()]);
        else if(it != v.begin())
            printf("%d\n", preSum[it - v.begin() - 1]);
        else
            printf("0\n");
    }

    return 0;
}