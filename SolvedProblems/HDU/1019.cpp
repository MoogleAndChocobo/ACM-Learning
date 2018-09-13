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

LL lcm(LL m, LL n)
{
	LL a = max(m, n);
	LL b = min(m, n);
	while(b)
	{
		LL tmp = a % b;
		a = b;
		b = tmp;
	}
	return (m / a) * n;
}

int main()
{
	int T;
	sfi(T);
	while(T--)
	{
		int n;
		sfi(n);
		LL pre = 0;
		sfl(pre);
		rep(i, 2, n)
		{
			LL tmp;
			sfl(tmp);
			pre = lcm(pre, tmp);
		}
		printf("%lld\n", pre);
	}
	
	return 0;
}