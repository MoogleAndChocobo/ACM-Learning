#include <stdio.h>

int main()
{
	int n;
	int s[30][30];
	while(~scanf("%d", &n))
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j <= i; j++)
			{
				if(j == 0 || i == j)
					s[i][j] = 1;
				else
					s[i][j] = s[i - 1][j - 1] + s[i - 1][j];
				
				printf("%d", s[i][j]);
				if(i != j)
					printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
}