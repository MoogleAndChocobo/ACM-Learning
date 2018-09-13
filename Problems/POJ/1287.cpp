#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define rep(a, b) for(int i = (int)a; i <= (int)b; i++)

const int MAX = 1e2 + 10;

struct Ufs
{
	int prt[MAX];
	void init(int n)
	{
		rep(1, n)
			prt[i] = i;
	}
	int find(int x)
	{
		while(x != prt[x])
			x = prt[x];
		return x;
	}
	bool unite(int x, int y)
	{
		int fx = find(x);
		int fy = find(y);
		prt[x] = prt[y] = prt[fx] = prt[fy] = min(fx, fy);
		return fx != fy;
	}
};

struct Kruskal
{
	struct Edge
	{
		int u, v, w;
		Edge(int uu = 0, int vv = 0, int ww = 0):u(uu), v(vv), w(ww){}
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
		int ans = 0, cnt = 0;
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
	int city;
	while(~scanf("%d", &city))
	{
		if(!city)
			break;
		k.init();
		int n;
		scanf("%d", &n);
		rep(1, n)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			k.addedge(u, v, w);
		}
		printf("%d\n", k.solve(n));
	}
	return 0;
}