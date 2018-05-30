#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i <= b; ++j)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)

const int MAX = 1e2 + 5;
const int L = 2;
const LL MOD = 10000;

LL rec[MAX];

void init()
{
	rec[0] = 0;
	rec[1] = 1;
	rep(i, 2, 20)
		rec[i] = rec[i - 1] + rec[i - 2];
}


LL solve(LL n)
{
	double t = n*log10((1+sqrt(5.))/2.)-log10(sqrt(5.));
	t -= LL(t);
	t = pow(10, t);
	while(t < 1000.)
		t *= 10.;
	return LL(t);
}

int main()
{
	init();
	
	LL n;
	while(~scanf("%lld", &n))
	{
		if(n <= 20LL)
			printf("%lld\n", rec[n]);
		else
			printf("%lld\n", solve(n));
	}
	return 0;
}
