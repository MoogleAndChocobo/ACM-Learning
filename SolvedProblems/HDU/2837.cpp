#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)

const int MAX = 4e6 + 10;
const int N = 4e6;
const LL MOD = 1e9 + 7;

LL fpow(LL a, LL b, LL mod)
{
	if(a >= mod)
		a = a % mod + mod;
	LL ans = 1;
	while(b)
	{
		if(b & 1)
		{
			ans *= a;
			if(ans >= mod)
				ans = ans % mod + mod;
		}
		a *= a;
		if(a >= mod)
			a = a % mod + mod;
		b >>= 1;
	}
	return ans;
}

LL eular(LL n)
{
	LL res = n, a = n;
	for (LL i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			res = res / i * (i - 1);
			while (a % i == 0)
				a /= i;
		}
	}
	if (a > 1)
		res = res / a * (a - 1);
	return res;
}

LL f(LL n, LL mod)
{
	//~ if(mod == 1)
		//~ return 0;
	if(n == 0)
		return 1;
	return fpow(n % 10, f(n / 10, eular(mod)), mod);
}

int main()
{
	//~ printf("%lld\n", eular(2));

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		LL x, mod;
		scanf("%lld%lld", &x, &mod);
		printf("%lld\n", f(x, mod) % mod);
	}
	return 0;
}