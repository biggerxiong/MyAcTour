#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


using namespace std;

long long val[105];
int n;
int path[105], book[105] = {0};
vector<int> g[105];

void dfs(int step, int cur) {
    // printf("step = %d, cur = %d\n", step, cur);
    if (step == n - 1) {
        for (int i = 0; i < n - 1; i ++ ) {
            printf("%lld ", val[path[i]]);
        }
        printf("%lld\n", val[cur]);
        exit(0);
    }
    
    int next;
    for (int i = 0; i < g[cur].size(); i++) {
        next = g[cur][i];
        if (book[next] == 0) {
            path[step + 1] = next;
            book[next] = 1;
            dfs(step + 1, next);
            book[next] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    
    for (int i = 0; i < n; i ++ ) {
        for (int j = i + 1; j < n; j ++ ) {
            if (val[i] * 2 == val[j] || val[j] * 3 == val[i]) {
                g[i].push_back(j);
            } else if (val[j] * 2 == val[i] || val[i] * 3 == val[j]) {
                g[j].push_back(i);
            }
        }
    }
    
    // for (int i = 0; i < n; i ++ ) {
    //     printf("start %d: ", i);
    //     for (int j = 0; j < g[i].size(); j ++ ) {
    //         printf("%d ", g[i][j]);
    //     }
    //     printf("\n");
    // }
    
    for (int i = 0; i < n; i ++ ) {
        path[0] = i;
        book[i] = 1;
        dfs(0, i);
        book[i] = 0;
    }
}