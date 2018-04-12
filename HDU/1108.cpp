#include<iostream> //求最大公约数
using namespace std;

int gcd(int , int);			//最大公约数 
int lcm(int , int , int );  //最小公倍数，输入依次为a, b, 和他们的最大公约数 

int main() {
	int a, b, gcdNum;
	
	while (scanf("%d %d", &a, &b) != EOF) {
		gcdNum = gcd(a, b);
		cout << lcm(a, b, gcdNum) << endl;
	}	
	
	return 0;
} 

int gcd(int a, int b) {
	int c;
	c = a % b;
	if (c == 0)
		return b;
	else 
		return gcd(b, c);
}

int lcm(int a, int b, int c) {
	return a * b / c;
} 
