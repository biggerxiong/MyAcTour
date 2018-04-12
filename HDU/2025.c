#include<stdio.h>
#include<string.h>
char is(char );
int main()
{
	int i, len;
	char temp, str[105], ch;
	while (scanf(" %s", str) != EOF)
	{
		len = strlen(str);
		
		temp = str[0];
		
		for (i = 1; i < len; i++)
		{
			if (str[i] > temp)
			  temp = str[i];
		}
		
		for (i = 0; i < len; i++)
		{
			if (str[i] == temp)
				printf("%c(max)", str[i]);
			else
				printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}
