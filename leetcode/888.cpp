/*
 *create at 2018-08-16 15:47:14
 *author: XiongXuan
 */
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
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
    vector<string> uncommonFromSentences(string A, string B) {
        istringstream issa(A), issb(B);
        map<string, int> mapa, mapb;

        string temp;
        while(issa >> temp)
            mapa[temp]++;
        while(issb >> temp)
            mapa[temp]++;

        std::vector<string> v;
        for(auto it = mapa.begin(); it != mapa.end(); it++)
            if(it -> second == 1)
                v.push_back(it -> first);

        return v;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    string A = "this apple is sweet", B = "this apple is sour";
    Solution sol;
    auto v = sol.uncommonFromSentences(A, B);
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";

    return 0;
}