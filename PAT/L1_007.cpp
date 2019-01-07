#include<iostream>
using namespace std;

void output(char ch) {
	switch (ch) {
		case '-':
			cout << "fu";
			break;
		case '1':
			cout << "yi";
			break;
		case '2':
			cout << "er";
			break;
		case '3':
			cout << "san";
			break;
		case '4':
			cout << "si";
			break;
		case '5':
			cout << "wu";
			break;
		case '6':
			cout << "liu";
			break;
		case '7':
			cout << "qi";
			break;
		case '8':
			cout << "ba";
			break;
		case '9':
			cout << "jiu";
			break;
		case '0':
			cout << "ling";
			break;
	}
}
int main() {
	char ch;
	
	cin >> ch;
	output(ch);
	
	ch = getchar();
	while(ch != '\n') {
		cout << " ";
		output(ch);
		
		ch = getchar();
	}
	
	return 0;
}
