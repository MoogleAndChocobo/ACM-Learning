//~ #define LOCAL

#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)

const int MAX = 800;

bool store[MAX][MAX];
int rcnt;

struct Point
{
	int u, v;
	int x, y;
} s[MAX], road[MAX];

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
	}

	void addedge(int u, int v, double w)
	{
		e.push_back(Edge(u, v, w));
		return;
	}

	void solve(int n)
	{
		int cnt = 0;
		u.init(n);
		int len = e.size();
		sort(e.begin(), e.end());
		rep(0, len - 1)
		{
			if(u.unite(e[i].u, e[i].v))
			{
				cnt++;
				if(e[i].w != 0)
				{
					road[rcnt].u = e[i].u;
					road[rcnt++].v = e[i].v;
				}
			}
			if(cnt == n - 1)
				break;
		}
	}
} k;

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	rep(1, n)
		scanf("%d%d", &s[i].x, &s[i].y);

	int tmpnum;
	scanf("%d", &tmpnum);
	while(tmpnum--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		store[u][v] = store[v][u] = true;
	}

	rep(1, n - 1)
		for(int j = i + 1; j <= n; j++)
			if(!store[i][j])
			{
				double tmp = sqrt((double)(s[i].x - s[j].x) * (double)(s[i].x - s[j].x) + (double)(s[i].y - s[j].y) * (double)(s[i].y - s[j].y));
				k.addedge(i, j, tmp);
			}
			else
				k.addedge(i, j, 0);

	k.solve(n);

	rep(0, rcnt - 1)
		printf("%d %d\n", road[i].u, road[i].v);
	return 0;
}