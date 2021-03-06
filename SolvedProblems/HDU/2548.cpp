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
		double a, b, c, d;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		printf("%.3lf\n", d * (c / (a + b)));
	}
	return 0;
}