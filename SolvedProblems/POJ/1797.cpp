//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

const int MAX = 1e3 + 10;
const int INF = 0;

int g[MAX][MAX];
int dist[MAX];
bool vis[MAX];

void init(int n)
{
	mem(vis);
	rep(1, n + 1)
	{
		dist[i] = INF;
		for(int j = 1; j <= n; j++)
			g[i][j] = INF;
	}
	return;
}

int Dijkstra(int n)
{
	dist[1] = 0x3f3f3f3f;
	rep(1, n)
	{
		int idx = n + 1, mxdist = INF;
		for(int j = 1; j <= n; j++)
			if(!vis[j] && dist[j] > mxdist)
				idx = j, mxdist = dist[j];
		if(idx == n)
			break;
		vis[idx] = true;
		for(int j = 1; j <= n; j++)
			if(!vis[j])
				dist[j] = max(dist[j], min(g[idx][j], dist[idx]));
	}
	return dist[n];
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	int test;
	scanf("%d", &test);
	rep(1, test)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		init(n);
		while(m--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			g[u][v] = g[v][u] = max(g[u][v], w);
		}
		printf("Scenario #%d:\n%d\n\n", i, Dijkstra(n));
	}
	return 0;
}