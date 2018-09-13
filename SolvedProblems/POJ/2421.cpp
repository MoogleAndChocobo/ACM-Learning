#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX = 1e2 + 10;

int road[MAX][MAX];

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
		int u, v, w;
		Edge(int uu, int vv, int ww):u(uu), v(vv), w(ww){}
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

	void addedge(int u, int v, int w)
	{
		e.push_back(Edge(u, v, w));
	}

	int solve(int n)
	{
		u.init(n);
		int cnt = 0, ans = 0;
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
	k.init();
	int n;
	scanf("%d", &n);
	rep(1, n)
		for(int j = 1; j <= n; j++)
			scanf("%d", &road[i][j]);

	int num;
	scanf("%d", &num);
	while(num--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		road[x][y] = road[y][x] = 0;
	}

	rep(1, n - 1)
		for(int j = i + 1; j <= n; j++)
			k.addedge(i, j, road[i][j]);

	printf("%d\n", k.solve(n));
	return 0;
}