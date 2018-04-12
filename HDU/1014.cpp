#include<iostream>
#include<iomanip>
#include<cstring>
#include<time.h>
#include<cstdlib>
using namespace std;

int main() {
	int step, mod, i;
	int book[100000];
	
	while (scanf("%d %d", &step, &mod) != EOF) {
		memset(book, 0, sizeof(int) * mod);
			
		i = 0;
		while (1) {
			if (book[i] == 0) {
				book[i] = 1;
				i += step;
				if (i >= mod)
					i %= mod;
			}
			else {
				break;
			}
		}
		cout << setw(10) << step << setw(10) << mod << "    ";
		for (i = 0; i < mod; i++) {
			if (book[i] == 0)
				break;
		}
		if (i == mod) 
			cout << "Good Choice" << endl << endl;
		else 
			cout << "Bad Choice" << endl << endl;
	}
	
	return 0;
}
