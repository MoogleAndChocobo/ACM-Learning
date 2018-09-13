#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%lld", a)
#define sfd(a) scanf("%lf", &a)

const double PI = acos(-1.);
const int MAX = 1e4 + 5;
const int N = 1e7;
const double eps = 1e-8;

struct Point
{
	double x, y;
	Point(){}
	Point(double a, double b):x(a), y(b){}
	friend Point operator +(Point a, Point b)
	{
		return Point(a.x + b.x, a.y + b.y);
	}
	friend Point operator *(Point b, double a)
	{
		return Point(a * b.x, a * b.y);
	}
	friend Point operator /(Point b, double a)
	{
		return Point(b.x / a, b.y / a);
	}
};

double det(Point &a, Point &b)
{
	return a.x * b.y - a.y * b.x;
}

int cmp(double x)
{
	if(fabs(x) < eps)
		return 0;
	if(x > 0)
		return 1;
	return -1;
}

struct Polygon
{
	int n;
	Point a[MAX];
	double area()
	{
		double sum = 0;
		a[n] = a[0];
		rep(i, 0, n - 1)
			sum += det(a[i + 1], a[i]);
		return sum / 2;
	}
	Point MassCenter()
	{
		Point ans = Point(0,0);
		if(cmp(area()) == 0)
			return ans;
		a[n] = a[0];
		rep(i, 0, n - 1)
			ans = ans + (a[i] + a[i + 1]) * det(a[i + 1], a[i]);
		return ans / area() / 6;
	}
};

int main()
{

	int T;
	while(sfi(T) && T)
	{
		while(T--)
		{
			Polygon p;
			p.n = 3;
			scanf("%lf%lf%lf%lf%lf%lf", &p.a[0].x, &p.a[0].y, &p.a[1].x, &p.a[1].y, &p.a[2].x, &p.a[2].y);
			Point ans = p.MassCenter();
			printf("%.1lf %.1lf\n", ans.x, ans.y);
		}
	}
	return 0;
}