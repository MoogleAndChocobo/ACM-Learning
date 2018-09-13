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

const int MAX = 1e5 + 5;
const LL N = 5e5;
const LL MOD = 1e4;

LL s[MAX];

void init()
{
	rep(i, 1, 9999)
	{
		s[i] = (s[i - 1] + ((LL)i * (LL)i * (LL)i) % MOD) % MOD;
	}
}

int main()
{
	init();
	
	LL n;
	while(~sfl(n))
	{
		LL ans = (s[9999] * ((n / 9999) % MOD)) % MOD;
		ans += s[(int)(n % MOD)];
		ans %= MOD;
		printf("%04lld\n", ans);
	}
	
	return 0;
}