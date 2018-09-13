//~ #define LOCAL

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

const int MAX = 2 * 1e2 + 10;
const int INF = 0x3f3f3f3f;

int g[MAX][MAX];
int dist[MAX];
bool vis[MAX];

void init(int n)
{
	mem(vis);
	rep(0, n + 1)
	{
		dist[i] = INF;
		for(int j = 0; j <= n + 1; j++)
			g[i][j] = INF;
	}
	return;
}

int Dijkstra(int n, int st, int en)
{
	dist[st] = 0;
	rep(0, n)
	{
		int idx = n + 1, mndist = INF;
		for(int j = 0; j <= n; j++)
			if(!vis[j] && dist[j] < mndist)
				idx = j, mndist = dist[j];
		if(idx == en)
			break;
		vis[idx] = true;
		for(int j = 0; j <= n; j++)
			if(!vis[j])
				dist[j] = min(dist[j], g[idx][j] + dist[idx]);
	}
	if(dist[en] == INF)
		return -1;
	return dist[en];
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	int n, road;
	while(~scanf("%d%d", &n, &road))
	{
		n--;
		init(n);
		
		while(road--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			g[u][v] = g[v][u] = min(g[u][v], w);
		}
		
		int st, en;
		scanf("%d%d", &st, &en);
		printf("%d\n", Dijkstra(n, st, en));
	}
	return 0;
}