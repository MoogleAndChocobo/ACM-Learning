//#define LOCAL

#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

#define rep(a, b) for(int i = (int)a; i <= (int)b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX = 1e3 + 10;

struct Point
{
	double x, y, z, r;
} s[MAX];

struct Ufs
{
	int prt[MAX];

	void init(int n)
	{
		rep(1, n)
			prt[i] = i;
	}

	int findprt(int x)
	{
		while(x != prt[x])
			x = prt[x];
		return x;
	}

	bool unite(int x, int y)
	{
		int fx = findprt(x);
		int fy = findprt(y);
		prt[x] = prt[y] = prt[fx] = prt[fy] = min(fx, fy);
		return fx != fy;
	}
};

struct Kruskal
{
	struct Edge
	{
		int u, v;
		double w;
		Edge(int uu, int vv, double ww):u(uu), v(vv), w(ww){};
		friend bool operator< (Edge a, Edge b)
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
		int cnt = 0;
		double ans = 0;
		sort(e.begin(), e.end());
		int len = e.size();
		rep(0, len - 1)
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

int main()
{
/*#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif*/
	int n;
	while(~scanf("%d", &n))
	{
		if(!n)
			break;

		k.init();
		mst(s);
		rep(1, n)
			scanf("%lf%lf%lf%lf", &s[i].x, &s[i].y, &s[i].z, &s[i].r);

		rep(1, n - 1)
		{
			for(int j = i + 1; j <= n; j++)
			{
				double tmp = sqrt((s[i].x - s[j].x)*(s[i].x - s[j].x) + (s[i].y - s[j].y)*(s[i].y - s[j].y) + (s[i].z - s[j].z)*(s[i].z - s[j].z));
				if(tmp <= s[i].r + s[j].r)
					k.addedge(i, j, 0);
				else
					k.addedge(i, j, tmp - s[i].r - s[j].r);
			}
		}

		printf("%.3lf\n", k.solve(n));
	}
	return 0;
}