#include<iostream>
#include<cmath>
using namespace std;

int main() {
	double ans, a, b, c, k, s1, s2, t;
	double x1, x2, x3, y1, y2, y3;
	int cases;
	
	cin >> cases;
	while (cases--) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
		a = (y2 - y1) / ((x2 - x1) * (x2 - x1));
        b = -2 * a * x1;  
        c = y1 - a * x1 * x1 - b * x1;
        k = (y3 - y2) / (x3 - x2);
        t = y3 - k * x3;
        s1 = 1.0 / 3 * a * x3 * x3 * x3 + 1.0 / 2 * (b - k) * x3 * x3 + (c - t) * x3;
        s2 = 1.0 / 3 * a * x2 * x2 * x2 + 1.0 / 2 * (b - k) * x2 * x2 + (c - t) * x2;
        printf("%.2lf\n", s1 - s2);
	}
	
	return 0;
}
