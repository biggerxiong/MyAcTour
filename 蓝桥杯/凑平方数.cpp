/*
 *create at 2018-05-24 13:20:34
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#ifndef ONLINE_JUDGE
    #define db(str, arg, ...) printf(str, arg, ##__VA_ARGS__);
#else
    #define db(str, arg, ...) ;
#endif
#define inf 0x3f3f3f3f
const long long MAXN = 9876543210;

vector<long long> nums[11];
set<string> s;
long long path[11];
bool avail[10];

// 判断num这个数里是否有重复的数
bool con(long long num) {
    int book[10] = {0};
    while(num) {
        if(book[num % 10] == 1)
            return false;
        book[num % 10] = 1;
        num /= 10;
    }
    return true;
}

// 判断num是一个几位数
int f(long long num) {
    int n = 0;
    while(num) {
        n++;
        num /= 10;
    }
    return n;
}

// 算出所有的平方数
void init() {
    long long i = 0, temp;
    nums[1].push_back(0);
    for(i = 0; i * i <= MAXN; i++) {
        temp = i * i;
        if(con(temp)) nums[f(temp)].push_back(temp);
    }
    memset(avail, 1, sizeof(avail));
    memset(path, 0, sizeof(path));
}

// 打印出所有的平方数
void print() {
    for(int i = 0; i < 11; i++) {
        printf("\nn = %d:\n", i);
        for(unsigned int j = 0; j < nums[i].size(); j++)
            printf("%lld ", nums[i][j]);
    }
}

void dfs(int step, int remain) {
    if(remain == 0) {
        long long pathTemp[11];
        for(int i = 0; i < step; i++) pathTemp[i] = path[i];
        sort(pathTemp, pathTemp + step);
    
        string str = "";
        for(int i = 0; i < step; i++) {
            if(i) str += ",";
            str += to_string(pathTemp[i]);
        }
        s.insert(str);
        printf("insert into set  ");
        cout << str << endl;
        return;
    }

    for(int r = remain; r >= 1; r--) {
        for(unsigned int i = 0; i < nums[r].size(); i++) {
            long long tempa = nums[r][i], tempb = tempa;
            if(tempa == 0) { // 对0进行特判
                if(avail[0]) {
                    avail[0] = false;
                    path[step] = nums[r][i];
                    dfs(step + 1, remain - r);
                    avail[0] = true;
                }
            } else {
                while(tempa) {
                    if(!avail[tempa % 10]) break;
                    else avail[tempa % 10] = false;
                    tempa /= 10;
                }

                if(!tempa) {
                    path[step] = nums[r][i];
                    dfs(step + 1, remain - r);
                } 
                // 回退
                while(tempa != tempb) {
                    avail[tempb % 10] = true;
                    tempb /= 10;
                }
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    init();
    print();

    dfs(0, 10);
    printf("\nset size = %llu\n", s.size());

    return 0;
}