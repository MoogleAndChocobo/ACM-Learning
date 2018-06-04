#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <bitset>
#include <deque>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)
#define pb(a) push_back(a)
#define sync ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e2 + 5;
const int L = 2;
const LL MOD = 10000;
const int dir[MAX][MAX] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};

const double EPS = 1e-8;
const double PI = acos(-1.0);

typedef struct Point Point;
typedef struct Line Line;

int cmp(double x);
double sqr(double x);
double det(Point a, Point b);
double dot(Point a, Point b);
double dist(Point a, Point b);
Point rotate_point(Point p, double A);
bool parallel(Line a, Line b);
bool orthogonal(Line a, Line b);
Point PointProjLine(Point p, Line l, Point &ans);
Point reflect(Line l, Point p);
double dis_point_segment(Point p, Line l);
double dis_segment_segment(Line a, Line b);
Line point_make_line(Point a, Point b);
bool in_segment(Line l, Point p);
int dcmp(double k);
double mysqrt(double n);
Point rotate(Point p, double cost, double sint);
pair<Point, Point> crosspoint(Point ap, double ar, Point bp, double br);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
struct Point
{
	double x, y;
	Point() {}
	Point(double a, double b): x(a), y(b) {}

	friend Point operator -(Point a, Point b)
	{
		return Point(a.x-b.x,a.y-b.y);
	}
	friend Point operator +(Point a, Point b)
	{
		return Point(a.x+b.x,a.y+b.y);
	}
	friend bool operator ==(Point a, Point b)
	{
		return cmp(a.x-b.x)==0 && cmp(a.y-b.y)==0;
	}
	friend Point operator *(Point a, double b)
	{
		return Point(a.x*b,a.y*b);
	}
	friend Point operator *(double a, Point b)
	{
		return Point(a*b.x,a*b.y);
	}
	friend Point operator /(Point a, double b)
	{
		return Point(a.x/b,a.y/b);
	}
	double norm()
	{
		return sqrt(sqr(x)+sqr(y));
	}
};

struct Line
{
	Point a, b;
	Line() {}
	Line(Point x, Point y): a(x), b(y) {}
};

bool parallel(Line a, Line b)
{
	return !cmp(det(a.a-a.b,b.a-b.b));
}
	
bool orthogonal(Line a, Line b)
{
	return !cmp(dot(a.a - a.b, b.a - b.b));
}

Point PointProjLine(Point p, Line l)
{
	Point ans;
	double r = dot((l.b-l.a),(p-l.a))/dot(l.b-l.a,l.b-l.a);
	ans = l.a + r*(l.b-l.a);
	return ans;
}

int cmp(double x)
{
	if(abs(x) < EPS)
		return 0;
	if(x > 0)
		return 1;
	return -1;
}

double dis_point_segment(Point p, Line l)
{
	if(cmp(dot(p-l.a,l.b-l.a))<0)
		return (p-l.a).norm();
	if(cmp(dot(p-l.b,l.a-l.b))<0)
		return (p-l.b).norm();
	return abs(det(l.a-p,l.b-p))/dist(l.a,l.b);
}

bool line_make_point(Line a, Line b, Point &res)
{
	if(parallel(a,b))
		return false;
	double s1 = det(a.a-b.a,b.b-b.a);
	double s2 = det(a.b-b.a,b.b-b.a);
	res = (s1*a.b-s2*a.a)/(s1-s2);
	return true;
}

double dis_segment_segment(Line a, Line b)
{
	Point res;
	if(line_make_point(a, b, res) && in_segment(a, res) && in_segment(b, res))
		return 0.;
	return min(min(dis_point_segment(b.a, a), dis_point_segment(b.b, a)), min(dis_point_segment(a.a, b), dis_point_segment(a.b, b)));
}

double sqr(double x)
{
	return x * x;
}

double det(Point a, Point b)
{
	return a.x*b.y-a.y*b.x;
}

double dot(Point a, Point b)
{
	return a.x*b.x+a.y*b.y;
}
double dist(Point a, Point b)
{
	return (a-b).norm();
}

Point rotate_point(Point p, double A)
{
	double tx = p.x, ty = p.y;
	return Point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}

Point reflect(Line l, Point p)
{
	return p + ((PointProjLine(p, l) - p) * 2.0);
}

bool in_segment(Line l, Point p)
{
	bool fa = false, fb = false;
	if((cmp(p.x-l.a.x) != -1 && cmp(p.x-l.b.x) != 1) || (cmp(p.x-l.a.x) != 1 && cmp(p.x-l.b.x) != -1))
		fa = true;
	if((cmp(p.y-l.a.y) != -1 && cmp(p.y-l.b.y) != 1) || (cmp(p.y-l.a.y) != 1 && cmp(p.y-l.b.y) != -1))
		fb = true;
	return fa && fb;
}

int dcmp(double k)
{
	return k < -EPS ? -1 : k > EPS ? 1 : 0;
}

double mysqrt(double n)
{
	return sqrt(max(0.0, n));
}

void circle_cross_line(Point a, Point b, Point o, double r, Point ret[], int &num)
{
	double x0 = o.x, y0 = o.y;
	double x1 = a.x, y1 = a.y;
	double x2 = b.x, y2 = b.y;
	double dx = x2 - x1, dy = y2 - y1;
	double A = dx*dx+dy*dy;
	double B = 2*dx*(x1-x0)+2*dy*(y1-y0);
	double C = sqr(x1-x0)+sqr(y1-y0)-sqr(r);
	double delta = B*B-4*A*C;
	num = 0;
	if(dcmp(delta) >= 0)
	{
		double t1 = (-B - mysqrt(delta)) / (2*A);
		double t2 = (-B + mysqrt(delta)) / (2*A);
		ret[num++] = Point(x1 + t1*dx, y1 + t1*dy);
		ret[num++] = Point(x1 + t2*dx, y1 + t2*dy);
	}
	
}

Point rotate(Point p, double cost, double sint)
{
	double x = p.x, y = p.y;
	return Point(x*cost - y*sint, x*sint + y*cost);
}

pair<Point, Point> crosspoint(Point ap, double ar, Point bp, double br)
{
	double d = (ap - bp).norm();
	double cost = (ar*ar + d*d - br*br) / (2*ar*d);
	double sint = sqrt(1. - cost*cost);
	Point v = (bp - ap) / (bp - ap).norm() * ar;
	return make_pair(ap+rotate(v,cost,-sint),ap+rotate(v,cost,sint));
}

int main()
{	
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif

	Point a, b;
	double ar, br;
	scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &ar, &b.x, &b.y, &br);
	pair<Point, Point> ans = crosspoint(a, ar, b, br);
	Point m = ans.first, n = ans.second;
	if(m.x > n.x || (!cmp(m.x-n.x) && (m.y > n.y)))
		printf("%.7lf %.7lf %.7lf %.7lf\n", n.x, n.y, m.x, m.y);
	else
		printf("%.7lf %.7lf %.7lf %.7lf\n", m.x, m.y, n.x, n.y);
	return 0;
}
