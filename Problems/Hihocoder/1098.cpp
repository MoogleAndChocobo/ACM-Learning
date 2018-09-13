//~ #define LOCAL

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)

const int MAX = 1e5 + 10;

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
		return;
	}
	void addedge(int u, int v, int w)
	{
		e.push_back(Edge(u, v, w));
		return;
	}
	int solve(int n)
	{
		int cnt = 0, ans = 0;
		int len = e.size();
		u.init(n);
		sort(e.begin(), e.end());
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

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	int n, road;
	while(~scanf("%d%d", &n, &road))
	{
		k.init();
		while(road--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			k.addedge(u, v, w);
		}
		printf("%d", k.solve(n));
	}
	return 0;
}
