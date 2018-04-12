/*
 *creat at 2017-06-04 16:20:44
 *author :XiongXuan
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornr(i, n) for(int i = n - 1; i >= 0; i--)
#define eps 1e-8
#define PI 3.1415926

double getAns(double r,double R,double h,double H) {  
    double u = h / H * (R - r) + r;  
    return PI / 3 * (r * r + r * u + u * u) * h;  
}

int main () {
	int cases = 0;
	double r, R, H, V, temp;
	scanf("%d", &cases);

	while (cases--) {
		scanf("%lf %lf %lf %lf", &r, &R, &H, &V);

		double s = 1, e = 100, ans = (s + e) / 2.0;
		while (e - s < eps) {
			temp = getAns(r, R, ans, H);
			if (temp < V)
				s = ans;
			else 
				e = ans;

			ans = (s + e) / 2.0;
		}

		printf("%.6lf\n", ans);
	}

	return 0;
}