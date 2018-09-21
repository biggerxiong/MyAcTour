/*
 *create at 2018-08-23 15:22:36
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

class Solution {
public:
    int book[2005];
    vector<int> edges[2005];
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        init();
        for(auto it = dislikes.begin(); it != dislikes.end(); it++) {
            edges[(*it)[0]].push_back((*it)[1]);
            edges[(*it)[1]].push_back((*it)[0]);
        }
        
        queue<int> q;
        for(int i = 1; i <= N; i++) {
            // printf("check %d\n", i);
            if(book[i] == -1) {
                // printf("is -1\n");
                book[i] = 0;
                q.push(i);
                while(!q.empty()) {
                    int temp = q.front();  q.pop();
                    // printf("queue get %d\n", temp);
                    
                    for(auto it = edges[temp].begin(); it != edges[temp].end(); it++) {
                        // printf("queue for get %d, book is %d\n", *it, book[*it]);
                        if(book[*it] == -1) {
                            book[*it] = 1 - book[temp];
                            q.push(*it);
                        }
                        else if(book[temp] == book[*it])
                            return false;
                    }
                }
            }
        }
        return true;
    }
    
    void init() {
        memset(book, -1, sizeof(book));
        for(int i = 0; i < 2005; i++)
            edges[i].clear();
    }
};

