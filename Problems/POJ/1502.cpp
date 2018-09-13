//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

const int MAX = 1e2 + 10;
const int INF = 0x3f3f3f3f;

int g[MAX][MAX];
int dist[MAX];
bool vis[MAX];

void init(int n)
{
	mem(vis);
	rep(1, n)
	{
		dist[i] = INF;
		for(int j = 1; j <= n; j++)
			g[i][j] = INF;
	}
	return;
}

void Dijkstra(int n)
{
	dist[1] = 0;
	rep(1, n)
	{
		int idx = -1, mndist = INF;
		for(int j = 1; j <= n; j++)
			if(!vis[j] && dist[j] < mndist)
				idx = j, mndist = dist[j];
		vis[idx] = true;
		for(int j = 1; j <= n; j++)
			if(!vis[j])
				dist[j] = min(dist[j], g[idx][j] + dist[idx]);
	}
	return;
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	int n;
	while(~scanf("%d", &n))
	{
		init(n);

		rep(2, n)
		{
			for(int j = 1; j <= i - 1; j++)
			{
				char s[MAX];
				scanf("%s", s);
				if(isdigit(s[0]))
				{
					int num = atoi(s);
					g[i][j] = g[j][i] = num;
				}
			}
		}

		Dijkstra(n);
		
		int mx = 0;
		rep(1, n)
			mx = max(mx, dist[i]);
		printf("%d\n", mx);
	}
	return 0;
}