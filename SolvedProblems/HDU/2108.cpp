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
};

double len(double x1, double y1, double x2, double y2)
{
	return hypot(x1 - x2, y1 - y2);
}

double gt(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a = len(x1, y1, x2, y2);
	double b = len(x1, y1, x3, y3);
	double c = len(x2, y2, x3, y3);
	double p = (a + b + c) / 2.;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{

	int n;
	while(sfi(n) && n)
	{
		double sx[MAX], sy[MAX];
		Polygon p;
		p.n = n;
		rep(i, 0, n - 1)
			scanf("%lf%lf", &sx[i], &sy[i]);
		for(int i = 0, j = n - 1; i < n; i++, j--)
			p.a[i].x = sx[j], p.a[i].y = sy[j];
		double fact = p.area();
		double tarea = 0;
		rep(i, 1, n - 2)
			tarea += gt(p.a[0].x, p.a[0].y, p.a[i].x, p.a[i].y, p.a[i + 1].x, p.a[i + 1].y);
		puts(cmp(fact - tarea) == 0 ? "convex" : "concave");
	}
	return 0;
}