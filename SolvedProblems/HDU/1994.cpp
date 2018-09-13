#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)

const int MAX = 1e3 + 5;

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		double pre, day, r1, r2, r3;
		scanf("%lf%lf%lf%lf%lf", &pre, &day, &r1, &r2, &r3);
		double tmp = pre * (1.0 + r1 / 100.0 * day / 365.0);
		double x = tmp * (1 + r3 / 100.0);
		double y = pre * (1 + r2 / 100.0 * (day + 365.0) / 365.0);
		printf("%.1lf\n%.1lf\n", x, y);
	}
	return 0;
}