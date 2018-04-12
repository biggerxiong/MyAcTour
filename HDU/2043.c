#include<Stdio.h>
#include<string.h>
int main()
{
	char str[55];
	int i, a[5], m, j, len, sum;
	scanf("%d", &m);
	getchar();
	for (i = 0; i < m; i ++)
	{
		gets(str);
		sum = 0;
		len = strlen(str);
		if (len < 8 || len > 16)
			printf("NO\n");
		else
		{
			for (j = 0; j < 5; j ++)
				a[j] = 0;
				
			for (j = 0; j < len; j++)
			{
				if (str[j] >= 'A' && str[j] <= 'Z')
					a[1] = 1;
				else if (str[j] >= 'a' && str[j] <= 'z')
					a[2] = 1;
				else if (str[j] >= '0' && str[j] <= '9')
					a[3] = 1;
				else if(str[j] == '~' || str[j] == '!' || str[j] == '@' || str[j] == '#' || str[j] == '$'
						|| str[j] == '%' || str[j] == '^')
					a[4] = 1;
			}
			for (j = 1; j < 5; j ++)
			{
				if (a[j] == 1)
					sum ++;
			}
			if (sum >= 3)
				printf("YES\n");
			else 
				printf("NO\n");
		}
			
		
	}
}
