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
	if((p.x >= l.a.x && p.x <= l.b.x) || (p.x <= l.a.x && p.x >= l.b.x))
		fa = true;
	if((p.y >= l.a.y && p.y <= l.b.y) || (p.y <= l.a.y && p.y >= l.b.y))
		fb = true;
	return fa && fb;
}

int main()
{	
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif

	int T;
	sfi(T);
	while(T--)
	{
		Line a, b;
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &a.a.x, &a.a.y, &a.b.x, &a.b.y, &b.a.x, &b.a.y, &b.b.x, &b.b.y);
		printf("%.10lf\n", dis_segment_segment(a, b));
	}
	return 0;
}
