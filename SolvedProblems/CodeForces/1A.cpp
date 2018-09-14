#include<cstdio>

typedef long long LL;

int main()
{
	LL m, n, t;
	while(~scanf("%lld%lld%lld", &m, &n, &t))
	{
		LL t1 = m / t;
		if(m % t)
			t1++;
		LL t2 = n / t;
		if(n % t)
			t2++;
		printf("%lld\n", t1 * t2);
	}
	return 0;
}