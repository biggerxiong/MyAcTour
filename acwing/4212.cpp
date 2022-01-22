#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    
    char str1[1000], str2[1000];
    
    cin.getline(str1, 1000);
    cin.getline(str2, 1000);
    
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] -= 32;
        }
    }
    
    for (int i = 0; i < strlen(str2); i++) {
        if (str2[i] >= 'a' && str2[i] <= 'z') {
            str2[i] -= 32;
        }
    }
    
    int ans = strcmp(str1, str2);
    if (ans < 0) {
        cout << -1 << endl;
    } else if (ans == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}