#include <cstdio>
#include <iostream>
using namespace std;

struct DATA
{
	int a;
	int b;
	float c;
}s[1003];
typedef struct DATA data;

void selectSortForStruct(data a[], int n)
{
	int index, i, j;
	data t;
	for (i = 0; i < n; i ++)
	{
		index = i;
		for (j = i + 1; j < n; j ++)
		{
			if (a[index].c < a[j].c)
				index = j;
		}
		t = a[index];
		a[index] = a[i];
		a[i] = t;
	}
}

int main () {
	int n, sum, i;
	float ans = 0;

	cin >> n >> sum;
	for (i = 0; i < n; i++) 
		cin >> s[i].a;
	for (i = 0; i < n; i++) {
		cin >> s[i].b;
		s[i].c = s[i].b * 1.0 / s[i].a;
	}

	selectSortForStruct(s, n);

	for (i = 0; i < n; i++) {
		if (s[i].a > sum)
			break;

		sum -= s[i].a;
		ans += s[i].b;
	}

	if (sum) {
		ans += s[i].b * (sum * 1.0 / s[i].a);
	}

	printf("%.2f", ans);

	return 0;
}
