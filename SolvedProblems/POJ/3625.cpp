//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>

using namespace std;

const int MAX = 1e3 + 10;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

struct Point
{
	int x, y;
} s[MAX];

double g[MAX][MAX];
bool rec[MAX][MAX];

struct Ufs
{
	int prt[MAX];
	void init(int n)
	{
		rep(i, 1, n)
			prt[i] = i;
		return;
	}
	int findprt(int x)
	{
		if(x == prt[x])
			return x;
		return prt[x] = findprt(prt[x]);
	}
	bool unite(int x, int y)
	{
		int px = findprt(x);
		int py = findprt(y);
		prt[x] = prt[y] = prt[px] = prt[py] = min(px, py);
		return px != py;
	}
};

struct Kruskal
{
	struct Edge
	{
		int u, v;
		double w;
		Edge(int uu, int vv, double ww):u(uu), v(vv), w(ww){}
		friend bool operator <(Edge a, Edge b)
		{
			return a.w < b.w;
		}
	};
	vector<Edge> e;
	Ufs u;
	void init(void)
	{
		e.clear();
		return;
	}
	void addedge(int u, int v, double w)
	{
		e.push_back(Edge(u, v, w));
		return;
	}
	double solve(int n)
	{
		u.init(n);
		sort(e.begin(), e.end());
		double ans = 0;
		int cnt = 0, len = e.size();
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
		return ans;
	}
} k;

void init(void)
{
	mem(s);
	mem(g);
	k.init();
	return;
}


int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	int n, road;
	while(~scanf("%d%d", &n, &road))
	{
		init();
		rep(i, 1, n)
		{
			scanf("%d%d", &s[i].x, &s[i].y);
		}
		while(road--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			rec[u][v] = rec[v][u] = true;
		}
		rep(i, 1, n)
		{
			rep(j, 1, n)
			{
				if(i < j && !rec[i][j])
					g[i][j] = g[j][i] = sqrt((double)(s[i].x - s[j].x) * (double)(s[i].x - s[j].x) + (double)(s[i].y - s[j].y) * (double)(s[i].y - s[j].y));
			}
		}
		rep(i, 1, n)
		{
			rep(j, 1, n)
				if(i < j)
					k.addedge(i, j, g[i][j]);
		}
		printf("%.2lf\n", k.solve(n));
	}
	return 0;
}