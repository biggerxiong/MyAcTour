/*
 *create at 2018-09-10 14:18:35
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

void tolow(char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] <= 'Z' && str[i] >= 'A')
            str[i] += 'a' - 'A';
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif

    char word[15], article[1000005];
    gets(word);
    gets(article);

    tolow(word);
    tolow(article);
    int ans = 0, i, j, firstIndex = -1;
    for(i = 0; article[i] != '\0'; i++) {
        if((i > 0 && article[i - 1] == ' ' && article[i] == word[0])
            || (i == 0 && article[i] == word[0])) {
            db("i = %d\n", i);
            for(j = 0; word[j] != '\0' && article[i] != '\0'; i++, j++) {
                if(article[i] != word[j])
                    break;
            }
            db("break at i = %d, j = %d\n", i, j);
            if(word[j] == '\0') {
                if(article[i] == '\0' || article[i] == ' ') {
                    ans++;
                    if(ans == 1)
                        firstIndex = i - j;
                }
            }
        }
    }

    if(ans == 0)
        printf("-1\n");
    else
        printf("%d %d\n", ans, firstIndex);

    return 0;
}