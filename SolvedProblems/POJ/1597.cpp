#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b)
{
	if(a < b)
		swap(a, b);
	while(b)
	{
		LL tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	LL step, mod;
	while(~scanf("%lld%lld", &step, &mod))
	{
		if(gcd(step, mod) == 1)
			printf("%10lld%10lld    Good Choice\n\n", step, mod);
		else
			printf("%10lld%10lld    Bad Choice\n\n", step, mod);
	}
	return 0;
}