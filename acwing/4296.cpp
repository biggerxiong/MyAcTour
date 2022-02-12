#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    int y;
    for (int x = 0; x <= 1000; x++) {
        y = (n - a * x) / b;
        if (a * x + b * y == n) {
            cout << "YES" << endl << x << " " << y << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}

