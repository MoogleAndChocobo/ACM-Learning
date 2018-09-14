#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define mem(a) memset(a, 0, sizeof(a))
#define all(a) a.begin(), a.end()

const int MAX = 2e5 + 5;
const int N = 1e3;
const double eps = 1e-10;

double gtmin(double a, double b, double c, double d)
{
	double ans = min(a * d, b * c);
	ans = min(ans, a * c);
	ans = min(ans, b * d);
	return ans;
}

double gtmax(double a, double b, double c, double d)
{
	double ans = max(a * d, b * c);
	ans = max(ans, a * c);
	ans = max(ans, b * d);
	return ans;
}

int main()
{
	double a, b, c, d;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	double l = 0, r = 1.e9;
	rep(times, 1, 1000000)
	{
		double mid = (l + r) / 2;
		double p1 = a + mid, p2 = a - mid;
		double q1 = b + mid, q2 = b - mid;
		double m1 = c + mid, m2 = c - mid;
		double n1 = d + mid, n2 = d - mid;
		if(gtmin(q1, q2, m1, m2) <= gtmax(p1, p2, n1, n2) && gtmin(p1, p2, n1, n2) <= gtmax(q1, q2, m1, m2))
			r = mid;
		else
			l = mid;
	}
	printf("%.10lf\n", l);
	return 0;
}