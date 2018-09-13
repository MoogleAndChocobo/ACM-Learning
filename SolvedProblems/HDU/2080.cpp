#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%lld", a)

const double PI = acos(-1.);
const int MAX = 1e7 + 5;
const int N = 1e7;

double len(double x1, double y1, double x2, double y2)
{
	return hypot(x1 - x2, y1 - y2);
}

int main()
{

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		double x1, y1, x2, y2;
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		double a = len(x1, y1, 0, 0);
		double b = len(x2, y2, 0, 0);
		double c = len(x1, y1, x2, y2);
		double cost = (a * a + b * b - c * c) / (2 * a * b);
		printf("%.2lf\n", acos(cost) / PI * 180);
	}
	return 0;
}