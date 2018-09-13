//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int INIT = INF;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define msf(a) memset(a, INF, sizeof(a))

int g[MAX][MAX];
int dis[MAX];
bool vis[MAX];

void Dijkstra(int n, int st)
{
	mem(vis);
	rep(1, n + 1)
		dis[i] = INIT;

	dis[st] = 0;
	rep(1, n)
	{
		int idx = n + 1, tmp = INIT;
		for(int j = 1; j <= n; j++)
			if(!vis[j] && tmp > dis[j])
				idx = j, tmp = dis[j];
		vis[idx] = true;
		for(int j = 1; j <= n; j++)
			if(!vis[j])
				dis[j] = min(dis[j], g[idx][j] + dis[idx]);
	}
	return;
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int n, road, en;
	scanf("%d%d%d", &n, &road, &en);

	rep(1, n)
		for(int j = 1; j <= n; j++)
			g[i][j] = INIT;
	
	while(road--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u][v] = min(g[u][v], w);
	}

	int ans[MAX], mx = 0;
	Dijkstra(n, en);
	rep(1, n)
		ans[i] = dis[i];

	rep(1, n)
		for(int j = 1; j <= i; j++)
			swap(g[i][j], g[j][i]);

	Dijkstra(n, en);
	rep(1, n)
		ans[i] += dis[i];

	rep(1, n)
		mx = max(mx, ans[i]);
	printf("%d\n", mx);
	return 0;
}