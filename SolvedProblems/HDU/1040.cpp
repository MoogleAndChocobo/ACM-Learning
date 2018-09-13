#include <stdio.h>

int main()
{
	int num, n;
	while(~scanf("%d", &n))
	{
		for(int i = 0; i < n; i++)
		{
			int num;
			scanf("%d", &num);
			int s[1000] = {0};
			for(int j = 0; j < num; j++)
				scanf("%d", &s[j]);
			for(int j = 0; j < num; j++)
			{
				for(int k = 1; k < num - j; k++)
				{
					if(s[k] < s[k - 1])
					{
						int temp = s[k];
						s[k] = s[k - 1];
						s[k - 1] = temp;
					}
				}
			}
			for(int j = 0; j < num; j++)
			{
				printf("%d", s[j]);
				if(j != num - 1)
					printf(" ");
				else
					printf("\n");
			}
		}
	}
}