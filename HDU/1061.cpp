#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    while (n--)
    {
        int m;
        cin >> m;
        int a[10][5] = {
        {0,0,0,0,0},
		{1,1,1,1,1},
		{6,2,4,8,6},
		{1,3,9,7,1},
		{6,4,6,4,6},
		{5,5,5,5,5},
		{6,6,6,6,6},
		{1,7,9,3,1},
		{6,8,4,2,6},
		{1,9,1,9,1}};
        cout << a[m % 10][m % 4] << endl;
    }
    
    return 0;
}
