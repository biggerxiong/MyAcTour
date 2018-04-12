#include<stdio.h>
int main()
{
	char ch, last;
	while (scanf("%c", &ch) != EOF)
	{
		last = ch;
		putchar(ch - 32);
		while (scanf("%c", &ch) && ch != '\n')
		{
			if (last == ' ')
			{
				last = ch;
				putchar(ch - 32);
			}
			else 
			{
				last = ch;
				putchar(ch);
			}
		}
		putchar('\n');
	}
	return 0;
}
