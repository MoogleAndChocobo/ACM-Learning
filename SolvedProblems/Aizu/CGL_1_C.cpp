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
 
const int MAXN = 1000 + 5;
const double EPS = 1e-6;
const double PI = acos(-1.0);

const int L = 2;
const LL MOD = 100000 + 50;
const int MAX = 100000 + 50;

typedef struct Point Point;
typedef struct Line Line;
typedef struct Polygon Polygon;
typedef struct Polygon_convex Polygon_convex;
 
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
bool PointOnSegment(Point p, Point s, Point t);
bool comp_less(Point a, Point b);
Polygon_convex convex_hull(vector<Point> a);
double convex_diameter(Polygon_convex a, int &First, int &Second);
double min_dist(Point a[], int s[], int l, int r);
double Min_Dist(Point a[], int s[], int n);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
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
 
struct Polygon
{
    int n;
    Point a[80050];
    Polygon() {}
    double perimeter()
    {
		double sum = 0;
		a[n] = a[0];
		rep(i, 0, n - 1)
			sum += (a[i+1]-a[i]).norm();
		return sum;
	}
    int Point_In(Point t)
    {
        int num = 0;
        a[n] = a[0];
        rep(i, 0, n - 1)
        {
            if(PointOnSegment(t, a[i], a[i + 1]))
                return 2;
            int k = cmp(det(a[i + 1] - a[i], t - a[i]));
            int d1 = cmp(a[i].y - t.y);
            int d2 = cmp(a[i + 1].y - t.y);
            if(k > 0 && d1 <= 0 && d2 > 0)
                num++;
            if(k < 0 && d2 <= 0 && d1 > 0)
                num--;
        }
        return num != 0;
    }
};
 
struct Polygon_convex
{
    vector<Point> P;
    Polygon_convex(int Size = 0)
    {
        P.resize(Size);
    }
};

bool comp_less(Point a, Point b)
{
    return cmp(a.x-b.x)<0 || cmp(a.x-b.x)==0 && cmp(a.y-b.y)<0;
}

Polygon_convex convex_hull(vector<Point> a)
{
	Polygon_convex res(2*a.size()+5);
    sort(a.begin(), a.end(), comp_less);
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = 0;
    int len = a.size();
    rep(i, 0, len - 1)
    {
        while(m>1&&cmp(det(res.P[m-1]-res.P[m-2],a[i]-res.P[m-2]))<=0)
            --m;
        res.P[m++] = a[i];
    }
    int k = m;
    len = a.size();
    dow(i, len - 2, 0)
    {
        while(m>k && cmp(det(res.P[m-1]-res.P[m-2],a[i]-res.P[m-2]))<=0)
            --m;
        res.P[m++] = a[i];
    }
    res.P.resize(m);
    if(a.size()>1)
        res.P.resize(m-1);
       return res;
}

bool PointOnSegment(Point p, Point s, Point t)
{
    return cmp(det(p-s,t-s)) == 0 && cmp(dot(p-s,p-t))<=0;
}
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

double convex_diameter(Polygon_convex a, int &First, int &Second)
{
	vector<Point> &p = a.P;
	int n = p.size();
	double maxd = 0.0;
	if(n == 1)
	{
		First = Second = 0;
		return maxd;
	}
	#define next(i) ((i+1)%n)
	for(int i = 0, j = 1; i < n; ++i)
	{
		while(cmp(det(p[next(i)]-p[i],p[j]-p[i])-det(p[next(i)]-p[i],p[next(j)]-p[i]))<0)
			j = next(j);
		double d = dist(p[i], p[j]);
		if(d > maxd)
		{
			maxd = d;
			First = i, Second = j;
		}
		d = dist(p[next(i)],p[next(j)]);
		if(d > maxd)
		{
			maxd = d;
			First = i, Second = j;
		}
	}
	return maxd;
}


void ccw(Point p0, Point p1, Point p2)
{
	Point a = p1 - p0;
	Point b = p2 - p0;
	if(det(a, b) > EPS)
		puts("COUNTER_CLOCKWISE");
	else if(det(a, b) < -EPS)
		puts("CLOCKWISE");
	else if(dot(a, b) < -EPS)
		puts("ONLINE_BACK");
	else if(a.norm() < b.norm())
		puts("ONLINE_FRONT");
	else
		puts("ON_SEGMENT");
}

int main()
{   
#ifdef LOCAL
    //~ freopen("in.txt", "r", stdin);
#endif
 
	Point a, b, c;
	scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
	int n;
	sfi(n);
	while(n--)
	{
		scanf("%lf%lf", &c.x, &c.y);
		ccw(a, b, c);
	}
    return 0;
}