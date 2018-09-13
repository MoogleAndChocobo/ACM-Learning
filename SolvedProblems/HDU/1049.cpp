#include <stdio.h>

int main()
{
	int sum, step, rest;
	while(~scanf("%d%d%d", &sum, &step, &rest))
	{
		if(sum == 0 && step == 0 & rest == 0)
			break;
		int re = 0;
		while(sum > step)
		{
			sum -= step - rest;
			re += 2;
		}
		re++;
		printf("%d\n", re);
	}
}