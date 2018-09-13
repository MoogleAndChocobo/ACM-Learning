#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 5 * 1e2 + 10;
const int INF = 0x3f3f3f3f;
const int INIT = INF;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

int dis[MAX];
int cnt;

struct Edge
{
	int u, v, w;
} e[MAX * MAX];

void init(int n)
{
	cnt = 0;
	mem(e);
	rep(1, n)
		dis[i] = INIT;
	return;
}

void addedge(int u, int v, int w)
{
	e[cnt].u = u;
	e[cnt].v = v;
	e[cnt++].w = w;
	return;
}

bool Bellman(int n, int st)
{
	dis[st] = 0;
	rep(1, n - 1)
	{
		for(int j = 0; j < cnt; j++)
		{
			dis[e[j].u] = min(dis[e[j].u], dis[e[j].v] + e[j].w);
		}
	}

	rep(0, cnt - 1)
	{
		if(dis[e[i].u] > dis[e[i].v] + e[i].w)
		{
			return true;
		}
	}
	return false;
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n, rroad, sroad;
		scanf("%d%d%d", &n, &rroad, &sroad);
		init(n);
		while(rroad--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addedge(u, v, w);
			addedge(v, u, w);
		}
		while(sroad--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addedge(u, v, -w);
		}
		if(Bellman(n, 1))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}