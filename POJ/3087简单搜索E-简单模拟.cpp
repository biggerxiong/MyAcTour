#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void merge(char *, char *, char *);
void split(char *, char *, char *);

int n;
int main () {
	char s1[104], s2[104], s12[208], initS[208], end[208] = "";
	int cases, time = 0, i, ans;

	cin >> cases;
	while (time++ < cases) {
		cin >> n >> s1 >> s2 >> s12;
		strcpy(initS, s1);
		strcat(initS, s2);
		ans = -1;
		
//		puts(s1);
//		puts(s2);
//		puts(s12);
//		puts(initS);
		
		while (true) {
//			cout << 1 << endl;
			merge(s1, s2, end);
			ans++;
			if (!strcmp(end, s12)) {
				printf("%d %d\n", time, ans + 1);
				break;
			}
			else if (!strcmp(end, initS)){
				printf("%d %d\n", time, -1);
				break;
			}
			else {
				split(s1, s2, end);
			}
		}
	}
	return 0;
}

void merge(char *s1, char *s2, char *end) {
	int i, index = 0;
	for (i = 0; i < n; i++) {
		end[index++] = s2[i];
		end[index++] = s1[i];
	}
	end[index++] = '\0';
//	printf("merge : s1 %s  s2 %s  end %s\n", s1, s2, end);
}

void split(char *s1, char *s2, char *end) {
	strcpy(s2, end + n);
	end[n] = '\0';
	strcpy(s1, end);
//	printf("split : s1 %s  s2 %s  end %s\n", s1, s2, end);
}
