#include <stdio.h>

int main()
{
	int n;
	long long s[100];
	s[1] = 2;
	while(~scanf("%d", &n))
	{
		for(int i = 2; i <= n; i++)
			s[i] = 3 * s[i - 1] + 2;
		printf("%I64d\n", s[n]);
	}
}