//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 1e2 + 10;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define msf(a) memset(a, INF, sizeof(a))

int pic[MAX][MAX];
int rec[MAX];
int dis[MAX];
bool vis[MAX];

void Dijkstra(int n, int st)
{
	msf(dis);
	mem(vis);
	dis[st] = 0;
	rep(i, 1, n)
	{
		int idx = n + 1, tmp = INF;
		rep(j, 1, n)
			if(!vis[j] && dis[j] < tmp)
				idx = j, tmp = dis[j];
		vis[idx] = true;
		rep(j, 1, n)
			if(!vis[j])
				dis[j] = min(dis[j], dis[idx] + pic[idx][j]);
	}
	int cnt = 0;
	rep(i, 1, n)
		if(dis[i] != INF)
		{
			rec[i]++;
			cnt++;
		}
	rec[st] += cnt;
	return;
}

void init(int n)
{
	msf(dis);
	rep(i, 1, n)
		msf(pic);
	mem(rec);
	mem(vis);
	return;
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	int n, road;
	while(~scanf("%d%d", &n, &road))
	{
		init(n);
		while(road--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			pic[u][v] = 1;
		}

		rep(i, 1, n)
			Dijkstra(n, i);

		int ans = 0;
		rep(i, 1, n)
			if(rec[i] == n + 1)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}