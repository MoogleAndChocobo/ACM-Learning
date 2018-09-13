//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<iostream>
#include<cmath>
#include<cctype>
#include<sstream>
#include<iomanip>
#include<ctime>
#include<bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned U;

const int MAX = 1e2 + 10;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;
const double EPS = 0.00000001;
const int MOD = 1e9 + 7;
const LL LMOD = 1e9 + 7;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)
#define pb(a) push_back(a)
#define mem(a) memset(a, 0, sizeof(a))
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mst(a, b) memset(a, b, sizeof(a))

struct Point
{
	double x, y;
	Point(double xx = 0.0, double yy = 0.0):x(xx), y(yy){}
} point[MAX];

struct Ufs
{
	int prt[MAX];

	void init(int n)
	{
		rep(i, 1, n)
			prt[i] = i;
	}

	int findprt(int n)
	{
		while(n != prt[n])
			n = prt[n];
		return n;
	}

	bool unite(int x, int y)
	{
		int px = findprt(x);
		int py = findprt(y);
		prt[x] = prt[y] = prt[px] = prt[py] = min(px, py);
		return px != py;
	}

	bool getcnt(int n)
	{
		set<int> ans;
		rep(i, 1, n)
			ans.insert(findprt(i));
		return ans.size() == 1;
	}
};

struct Kruskal
{
	struct Edge
	{
		int u, v;
		double w;
		Edge(int uu = 0, int vv = 0, double ww = 0.0):u(uu), v(vv), w(ww){}
		friend bool operator <(Edge a, Edge b)
		{
			return a.w < b.w;
		}
	};

	vector<Edge> e;
	Ufs u;

	void init(int n)
	{
		u.init(n);
		e.clear();
	}

	void addedge(int u, int v, double w)
	{
		e.pb(Edge(u, v, w));
	}

	void solve(int n)
	{
		sort(e.begin(), e.end());
		int len = e.size(), cnt = 0;
		double ans = 0;
		rep(i, 0, len - 1)
		{
			if(u.unite(e[i].u, e[i].v))
			{
				cnt++;
				ans += e[i].w;
			}
			if(cnt == n - 1)
				break;
		}
		if(u.getcnt(n))
			printf("%.1lf\n", ans * 100);
		else
			printf("oh!\n");
	}
} k;

double getlen(double x1, double x2, double y1, double y2)
{
	return hypot(x1 - x2, y1 - y2);
}

bool check(double x)
{
	if(x >= 10 && x <= 1000)
		return true;
	return false;
}

int main()
{
	
#ifdef LOCAL
	fropen("in.txt", "r", stdin);
#endif	//LOCAL

	//~ ios::sync_with_stdio(false);
	//~ cin.tie(0);

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int n;
		sfi(n);
		if(n == 0)
		{
			puts("0.0");
			continue;
		}
		rep(i, 1, n)
			scanf("%lf%lf", &point[i].x, &point[i].y);

		k.init(n);
		rep(i, 1, n)
		{
			rep(j, 1, i - 1)
			{
				double len = getlen(point[i].x, point[j].x, point[i].y, point[j].y);
				if(check(len))
					k.addedge(i, j, len);
			}
		}
		k.solve(n);
	}
	return 0;
}