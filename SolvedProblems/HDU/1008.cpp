#include <stdio.h>

int main()
{
	int num;
	int s[1000];
	s[0] = 0;
	while(~scanf("%d", &num))
	{
		if(num == 0)
			break;
		int sum = num * 5;
		for(int i = 1; i <= num; i++)
		{
			scanf("%d", &s[i]);
			if(s[i] > s[i - 1])
				sum += (s[i] - s[i - 1]) * 6;
			else
				sum += (s[i - 1] - s[i]) * 4;
		}
		printf("%d\n", sum);
	}
}