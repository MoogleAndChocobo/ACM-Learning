#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define sfl(a) scanf("%lld", &a)
#define sfi(a) scanf("%d", &a)

const int MAX = 1e5 + 5;
const int N = 99999;
const LL MOD = 1007;

double ans[MAX];

void init()
{
	double now = 0;
	rep(i, 1, N)
	{
		now += 1.0 / (2.0 * i);
		ans[i] = now;
	}
}

int main()
{
	init();

	int n;
	puts("# Cards  Overhang");
	while(~sfi(n))
	{
		printf("%5d     %.3lf\n", n, ans[n]);
	}
	return 0;
}