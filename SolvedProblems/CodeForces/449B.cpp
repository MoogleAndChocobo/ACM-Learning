#include <bits/stdc++.h>

using namespace std;

#define sfi(a) scanf("%d", &a)
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

typedef long long LL;

const int N = 1e5 + 10;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n, m, k;
int reccnt[N];
bool vis[N];
LL recmin[N];
LL dis[N];
vector<pair<int, int> > g[N];
queue<int> q;

void Spfa()
{
	dis[1] = 0;
	q.push(1);
	vis[1] = true;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		int len = g[u].size();
		rep(i, 0, len - 1)
		{
			if(dis[u] + g[u][i].second < dis[g[u][i].first])
			{
				dis[g[u][i].first] = dis[u] + g[u][i].second;
				reccnt[g[u][i].first] = reccnt[u];
				if(!vis[g[u][i].first])
				{
					vis[g[u][i].first] = true;
					q.push(g[u][i].first);
				}
			}
			else if(dis[u] + g[u][i].second == dis[g[u][i].first])
			{
				reccnt[g[u][i].first] += reccnt[u];
				reccnt[g[u][i].first] = reccnt[g[u][i].first] >= 2 ? 2 : reccnt[g[u][i].first]; 
			}
		}
		vis[u] = false;
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, m)
	{
		int u, v;
		LL w;
		scanf("%d%d%lld", &u, &v, &w);
		g[u].push_back(pair<int,int>(v,w));
		g[v].push_back(pair<int,int>(u,w));
	}
	reccnt[1] = 1;
	rep(i, 1, n)
		recmin[i] = dis[i] = LINF;
	rep(i, 1, k)
	{
		LL x, y;
		scanf("%lld%lld", &x, &y);
		recmin[x] = min(recmin[x], y);
	}
	LL ans = k;
	rep(i, 1, n)
	{
		if(recmin[i] != LINF)
		{
			g[i].push_back(pair<int,int>(1, recmin[i]));
			g[1].push_back(pair<int,int>(i, recmin[i]));
			ans--;
		}
	}
	Spfa();
	rep(i, 1, n)
	{
		//~ printf("%lld %d\n", dis[i], reccnt[i]);
		if(recmin[i] != LINF && (dis[i] < recmin[i] || (dis[i] == recmin[i] && reccnt[i] == 2)))
			ans++;
	}
	//~ putchar('\n');
	printf("%lld\n", ans);
	return 0;
}