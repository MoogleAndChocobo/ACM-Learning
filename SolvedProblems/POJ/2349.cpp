//#define LOCAL

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX = 1e3 + 10;

struct Point { double x, y; } s[MAX];
double road[MAX];

struct Ufs
{
	int prt[MAX];

	void init(int n)
	{
		rep(1, n)
			prt[i] = i;
		return;
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
		Edge(int uu, int vv, double ww):u(uu), v(vv), w(ww){}
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
	}

	void addedge(int u, int v, double w)
	{
		e.push_back(Edge(u, v, w));
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
				ans += e[i].w;
				road[cnt++] = e[i].w;
			}
			if(cnt == n - 1)
				break;
		}
		return ans;
	}
} k;

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	int test;
	scanf("%d", &test);
	while(test--)
	{
		k.init();
		mst(s);
		mst(road);
		
		int sate, n;
		scanf("%d%d", &sate, &n);
		rep(1, n)
			scanf("%lf%lf", &s[i].x, &s[i].y);
		rep(1, n - 1)
		{
			for(int j = i + 1; j <= n; j++)
			{
				double tmp = sqrt((s[i].x - s[j].x) * (s[i].x - s[j].x) + (s[i].y - s[j].y) * (s[i].y - s[j].y));
				k.addedge(i, j, tmp);
			}
		}

		k.solve(n);
		sort(road, road + n - 1);
		printf("%.2lf\n", road[n - sate - 1]);
	}
	return 0;
}