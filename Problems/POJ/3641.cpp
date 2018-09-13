#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;

ll fpow(ll a, ll b)
{
	ll base = 1;
	a %= b;
	ll p = b;
	while (b)
	{
		if (b & 1)
			base = base * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return base;
}

bool prime(ll x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int main()
{
	ll a, b;
	while (scanf("%lld%lld", &b, &a) == 2 && a + b)
	{
		if (fpow(a, b) == a % b && !prime(b))
			printf("yes\n");
		else
			printf("no\n");
	}
	 return 0;
}