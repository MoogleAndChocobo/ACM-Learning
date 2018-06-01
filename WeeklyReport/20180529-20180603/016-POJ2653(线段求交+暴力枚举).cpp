#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%l", &a)
#define sfu(a) scanf("%llu", &a)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()

const int MAX = 1e5 + 50;
const int N = 1e3;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const double PI = acos(-1.0);

typedef struct Point Point;
typedef struct Line Line;

int cmp(double x);
inline double sqr(double x);
double det(const Point &a, const Point &b);
double dot(const Point &a, const Point &b);
double dist(const Point &a, const Point &b);
Point rotate_point(const Point &p, double A);
Line point_make_line(const Point a, const Point b);
double dis_point_segment(const Point p, const Point s, const Point t);
void PointProjLine(const Point p, const Point s, const Point t, Point &cp);
bool PointOnSegment(Point p, Point s, Point t);
bool line_make_point(Line a, Line b, Point &res);
bool line_make_point(Line a, Line b, Point &res);
bool parallel(Line a, Line b);
bool in_mid(Line a, Line b, Point in);

struct Point {
	double x, y;
	Point() {}
	Point(double a, double b): x(a), y(b) {}
	void input()
	{
		scanf("%lf%lf", &x, &y);
	}
	friend Point operator +(const Point &a, const Point &b)
	{
		return Point(a.x+b.x, a.y+b.y);
	}
	friend Point operator -(const Point &a, const Point &b)
	{
		return Point(a.x-b.x, a.y-b.y);
	}
	friend bool operator ==(const Point &a, const Point &b)
	{
		return cmp(a.x-b.x) == 0 && cmp(a.y-b.y) == 0;
	}
	friend Point operator *(const Point &a, const double &b)
	{
		return Point(a.x*b, a.y*b);
	}
	friend Point operator *(const double &a, const Point &b)
	{
		return Point(a*b.x, a*b.y);
	}
	friend Point operator /(const Point &a, const double &b)
	{
		return Point(a.x/b, a.y/b);
	}
	double norm()
	{
		return sqrt(sqr(x) + sqr(y));
	}
};

struct Line
{
	Point a, b;
	Line() {}
	Line(Point x, Point y): a(x), b(y) {}
};

Line point_make_line(const Point a, const Point b)
{
	return Line(a, b);
}

double dis_point_segment(const Point p, const Point s, const Point t)
{
	if (cmp(dot(p-s,t-s)) < 0)
		return (p-s).norm();
	if (cmp(dot(p-t,s-t)) < 0)
		return (p-t).norm();
	return abs(det(s-p,t-p)/dist(s,t));
}

void PointProjLine(const Point p, const Point s, const Point t, Point &cp)
{
	double r = dot((t-s),(p-s))/dot(t-s,t-s);
	cp = s+r*(t-s);
}

bool PointOnSegment(Point p, Point s, Point t)
{
	return cmp(det(p-s,t-s))==0 && cmp(dot(p-s,p-t))<=0;
}

bool parallel(Line a, Line b)
{
	return !cmp(det(a.a-a.b,b.a-b.b));
}

bool line_make_point(Line a, Line b)
{
	if (parallel(a, b))
		return false;
	double s1 = det(a.a-b.a,b.b-b.a);
	double s2 = det(a.b-b.a,b.b-b.a);
	Point res = (s1*a.b-s2*a.a)/(s1-s2);
	return in_mid(a, b, res);
}

bool in_mid(Line a, Line b, Point in)
{
	bool f1 = false;
	bool f2 = false;
	if ((in.x >= a.a.x && in.x <= a.b.x) || (in.x <= a.a.x && in.x >= a.b.x))
		f1 = true;
	if ((in.x >= b.a.x && in.x <= b.b.x) || (in.x <= b.a.x && in.x >= b.b.x))
		f2 = true;
	return f1 && f2;
}

Line move_d(Line a, const double &len)
{
	Point d = a.b - a.a;
	d = d / d.norm();
	d = rotate_point(d, PI / 2);
	return Line(a.a+d*len,a.b+d*len);
}

double det(const Point &a, const Point &b)
{
	return a.x*b.y - a.y*b.x;
}

double dot(const Point &a, const Point &b)
{
	return a.x*b.x + a.y*b.y;
}

double dist(const Point &a, const Point &b)
{
		return (a - b).norm();
}

Point rotate_point(const Point &p, double A)
{
		double tx = p.x, ty = p.y;
		return Point(tx * cos(A) - ty * sin(A), tx * sin(A) + ty * cos(A));
}

int cmp(double x)
{
	if (abs(x) < EPS)
		return 0;
	if (x > 0)
		return 1;
	return -1;
}

inline double sqr(double x)
{
	return x * x;
}

Line s[MAX];
bool vis[MAX];
vector<int> ans;

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "r" , stdout);
#endif

	int n;
	while(~sfi(n) && n)
	{
		mem(vis);
		ans.clear();
		rep(i, 1, n)
		{
			double a, b, c, d;
			scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
			Point p1(a, b), p2(c, d);
			s[i] = Line(p1, p2);
		}
		
		rep(i, 1, n)
		{
			rep(j, i + 1, n)
				if(line_make_point(s[i], s[j]))
				{
					vis[i] = true;
					break;
				}
		}
		
		rep(i, 1, n)
			if(!vis[i])
				ans.pb(i);
		int len = ans.size();
		printf("Top sticks: ");
		rep(i, 0, len - 1)
		{
			printf("%d", ans[i]);
			if(i != len - 1)
				printf(", ");
			else
				printf(".\n");
		}
	}
	return 0;
}
