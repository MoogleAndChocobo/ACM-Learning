#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

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
	void link(int x, int y)
	{
		int px = findprt(x);
		int py = findprt(y);
		prt[x] = prt[y] = prt[px] = prt[py] = min(px, py);
		return;
	}
	int getnum(int n)
	{
		set<int> ans;
		rep(i, 1, n)
			ans.insert(findprt(i));
		return ans.size();
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
			return a.w > b.w;
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
		u.init(n);
		int ans = 0, cnt = 0, len = e.size();
		sort(e.begin(), e.end());
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
		if(u.getnum(n) == 1)
			return ans;
		return -1;
	}
} k;

int main()
{
	int n, road;
	scanf("%d%d", &n, &road);
	k.init();
	while(road--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		k.addedge(u, v, w);
	}
	printf("%d\n", k.solve(n));
	return 0;
}