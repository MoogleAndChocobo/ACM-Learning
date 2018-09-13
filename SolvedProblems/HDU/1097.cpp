#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b)("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define sfi(a) scanf("%d", &a)

const int MAX = 1e6 + 5;
const LL N = 5e5;
const LL MOD = 10;

LL ans[MAX];

LL f(LL a, LL b)
{
	a %= MOD;
	LL ans = 1;
	while(b)
	{
		if(b&1)
		{
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b>>=1;
	}
	return ans;
}

int main()
{
	LL a, b;
	while(~scanf("%lld%lld", &a, &b))
	{
		printf("%lld\n", f(a, b));
	}
	return 0;
}