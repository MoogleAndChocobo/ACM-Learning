#include <cstdio>
#include <cmath>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)

int fac(int n)
{
	double ans = 0;
	for(int i = 1; i <= n; i++)
		ans += log10((double)i);
	return ans + 1;
}

int main()
{
	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int n;
		sfi(n);
		printf("%d\n", fac(n));
	}
	return 0;
}