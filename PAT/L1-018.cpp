#include <stdio.h>

int main () {
	int hour, min, i, n;

	scanf("%d:%d", &hour, &min);

	if (hour < 12) {
		printf("Only %02d:%02d.  Too early to Dang.", hour, min);
	}
	else if (hour == 12 && min == 0)
		printf("Only %02d:%02d.  Too early to Dang.", hour, min);
	else {
		if (min == 0)
			n = hour - 12;
		else
			n = hour - 11;
			

		for (i = 0; i < n; i++)
			printf("Dang");
	}

	return 0;
}
