#include<iostream>
using namespace std;

struct DATA {
	int f, j;
	float tax;
}s[1005];

void selectSortForStruct(struct DATA a[], int n)
{
	int index, i, j;
	struct DATA t;
	for (i = 0; i < n; i ++)
	{
		index = i;
		for (j = i + 1; j < n; j ++)
		{
			if (a[index].tax < a[j].tax)
				index = j;
		}
		t = a[index];
		a[index] = a[i];
		a[i] = t;
	}
}

int main() {
	int m, n, f[1005], j[1005], i;
	double ans;
	
	while (cin >> m >> n && (m != -1 && n != -1)) {
		ans = 0;
		
		for (i = 0; i < n; i++) {
			cin >> s[i].j >> s[i].f;
			
			if (s[i].f == 0){
				s[i].tax = 0;
				ans += s[i].j;
			}
			else {
				s[i].tax = s[i].j * 1.0 / s[i].f;
			}
		}
		
		selectSortForStruct(s, n);
		
//		for (i = 0; i < n; i++) {
//			cout << s[i].j << s[i].f << s[i].tax << endl;
//		}

		for (i = 0; i < n; i++) {
			if (s[i].tax == 0)
				break;
			else if (m >= s[i].f) {
				m -= s[i].f;
				ans += s[i].j;
			}
			else {
				ans += m * 1.0 / s[i].f * s[i].j;
				break;
			}
		}
		
		printf("%.3f\n", ans);
	}
	
	return 0;
}
