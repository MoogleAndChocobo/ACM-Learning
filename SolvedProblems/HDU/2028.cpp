#include <stdio.h>
#include <math.h>

long long mie(long long m, long long n);

int main()
{
	int num;
	long long s[1000] = {0};
	while(~scanf("%d", &num))
	{
		long long re;
		for(int i = 1; i <= num; i++)
			scanf("%lld", &s[i]);
		re = s[1] * s[2] / mie(s[1], s[2]);
		for(int i = 3; i <= num; i++)
			re = re / mie(re, s[i]) * s[i];
		printf("%lld\n", re);
	}
}

long long mie(long long m, long long n)
{
	long long temp;
	if(n == 0)
		temp = m;
	else
		temp = mie(n, m % n);
	return temp;
}