//~ #define LOCAL

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 2 * 1e4 + 10;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

struct Ufs
{
	int prt[MAX];
	void init(int n)
	{
		rep(i, 0, n - 1)
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
		friend bool operator <(Edge a, Edge b)
		{
			return a.w < b.w;
		}
	};
	Ufs u;
	vector<Edge> e;
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
		sort(e.begin(), e.end());
		int ans = 0, cnt = 0, len = e.size();
		u.init(n);
		rep(i, 0, len - 1)
		{
			if(u.unite(e[i].u, e[i].v))
			{
				ans += e[i].w;
				cnt++;
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
#endif	//LOCAL

	int test;
	scanf("%d", &test);
	while(test--)
	{
		k.init();
		int n, m, road;
		scanf("%d%d%d", &n, &m, &road);
		while(road--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			w = -w;
			v += n;
			k.addedge(u, v, w);
		}
		printf("%d\n", 10000 * (m + n) + k.solve(m + n));
	}
	return 0;
}