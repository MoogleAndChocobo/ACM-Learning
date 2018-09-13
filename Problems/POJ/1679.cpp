#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX = 1e2 + 10;
const int INF = 0x3f3f3f3f;

bool road[MAX * MAX];

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

	int getnum(int n)
	{
		set<int> ans;
		rep(1, n)
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
		int cnt = 0, ans = 0;
		u.init(n);
		sort(e.begin(), e.end());
		int len = e.size();
		rep(0, len - 1)
		{
			if(u.unite(e[i].u, e[i].v))
			{
				ans += e[i].w;
				cnt++;
				road[i] = true;
			}
			if(cnt == n - 1)
				break;
		}

		bool flag = false;
		rep(0, len - 1)
		{
			if(!road[i])
				continue;

			u.init(n);
			int tmpcnt = 0, tmpans = 0;
			for(int j = 0; j <= len - 1; j++)
			{
				if(i == j)
					continue;
				if(u.unite(e[j].u, e[j].v))
				{
					tmpcnt++;
					tmpans += e[j].w;
				}
				if(tmpcnt == n - 1)
					break;
			}
			if(u.getnum(n) != 1)
				continue;
			if(tmpans == ans)
			{
				flag = true;
				break;
			}
		}
		if(flag)
			return -1;
		return ans;
	}
} k;

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		k.init();
		mst(road);
		
		int n, exist;
		scanf("%d%d", &n, &exist);
		while(exist--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			k.addedge(u, v, w);
		}

		int ans = k.solve(n);
		if(ans == -1)
			printf("Not Unique!\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}