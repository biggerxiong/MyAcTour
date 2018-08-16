/*
 *create at 2018-08-16 16:58:44
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
#ifndef ONLINE_JUDGE
    #define db(str, arg, ...) printf(str, arg, ##__VA_ARGS__);
#else
    #define db(str, arg, ...) ;
#endif
#define inf 0x3f3f3f3f
const int MAXN = 105;

class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int R, C;
    int book[105][105];
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        init(R, C);
        int face = 0, right = 1;
        int count = 0;
        int x = r0, y = c0;

        std::vector<std::vector<int>> ans;
        std::vector<int> temp;
        temp.push_back(r0); temp.push_back(c0);
        ans.push_back(temp);
        book[r0][c0] = 1;
        count++;
        while(count < R * C) {
            int rx = x + dir[right][0];
            int ry = y + dir[right][1];
            // 如果右边可以走，就转弯
            if(outBound(rx, ry) == true || booked(rx, ry) == false) {
                face = right;
                right = (face + 1) % 4;
            }

            x = x + dir[face][0];
            y = y + dir[face][1];
            if(outBound(x, y) == false) {
                temp[0] = x;
                temp[1] = y;
                ans.push_back(temp);
                book[x][y] = 1;
                count++;
                // printf("test %d %d\n", x, y);
            }
        }
        return ans;
    }

    bool outBound(int x, int y) {
        if(x < 0 || y < 0 || x >= R || y >= C)
            return true;
        return false;
    }

    bool booked(int x, int y) {
        if(book[x][y] == 1)
            return true;
        return false;
    }

    void init(int r, int c) {
        this -> R = r;
        this -> C = c;
        memset(book, 0, sizeof(book));
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    Solution sol;
    int R = 5, C = 6, r0 = 1, c0 = 4;
    auto v = sol.spiralMatrixIII(R, C, r0, c0);
    for(auto it : v)
        printf("%d %d\n", it[0], it[1]);

    return 0;
}