#include<stdio.h>
#include<string.h>
int main ()
{
	char ch;
	int n, i;
	int num[5] = {0}, j;
	
	scanf ("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 5; j ++)
			num[j] = 0;
		while (scanf("%c", &ch) != EOF && ch != '\n')
		{
			switch (ch)
			{
				case 'a':
				case 'A':
					num[0]++;
					break;
				case 'e':
				case 'E':
					num[1]++;
					break;
				case 'i':
				case 'I':
					num[2]++;
					break;
				case 'o':
				case 'O':
					num[3]++;
					break;
				case 'u':
				case 'U':
					num[4]++;
					break;
			}
		}
		
		if (i == n - 1)
			break;
		else 
			printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n\n", num[0], num[1], num[2], num[3], num[4]);
	}
	printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", num[0], num[1], num[2], num[3], num[4]);
}
