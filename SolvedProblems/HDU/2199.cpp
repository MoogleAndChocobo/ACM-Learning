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
const double eps = 1e-9;

double f(double x)
{
	return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}

int main()
{
	int T;
	sfi(T);
	while(T--)
	{
		double y;
		sfd(y);
		if(f(0) > y || f(100) < y)
		{
			puts("No solution!");
			continue;
		}
		double l = 0., r = 100., mid, now;
		while(l + eps < r)
		{
			mid = (l + r) / 2.;
			now = f(mid);
			//~ printf("%lf %lf\n", mid, now);
			if(now == y)
				break;
			if(f(mid) < y)
				l = mid;
			else
				r = mid;
		}
		printf("%.4lf\n", (mid));
	}
	
	return 0;
}