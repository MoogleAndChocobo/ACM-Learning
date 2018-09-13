#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)

LL f(LL a, LL b, LL mod)
{
	a %= mod;
	LL ans = 1;
	while(b)
	{
		if(b & 1)
		{
			ans *= a;
			ans %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ans;
}

int main()
{
	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		LL a, b, mod;
		scanf("%lld%lld%lld", &a, &b, &mod);
		printf("%lld\n", f(a, b, mod));
	}
	return 0;
}