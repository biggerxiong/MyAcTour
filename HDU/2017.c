#include<stdio.h>

int main()

{

	char a;
	
	int n, cases, sum;

	
scanf("%d",&n);
	
	getchar();

	for (cases=1;cases<=n;cases++)

	{

		sum=0;

		while (scanf("%c",&a)
!=EOF )

		{

			if (a!='\n')

			{

				if (a>='0'&&a<='9')

				    sum++;

			}

			else

				break;

		}

		printf("%d\n",sum);

	}

	return 0;

}