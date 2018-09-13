//~ #define LOCAL

#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

typedef long long LL;

const int MAX = 1e6 + 10;
const LL INF = 0x3f3f3f3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

LL dis[MAX];
int head[MAX];
bool vis[MAX];
int cnt;

struct Edge
{
	int u, v, w, nxt;
} e[MAX], add[MAX];

struct Node
{
	int u, d;
	Node(int uu = 0, int dd = 0):u(uu), d(dd){}
	friend bool operator <(Node a, Node b)
	{
		return a.d > b.d;
	}
};

void init(int n)
{
	cnt = 0;
	mem(vis);
	rep(i, 1, n)
	{
		head[i] = -1;
		dis[i] = INF;
	}
	return;
}

void addedge(int u, int v, int w)
{
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
	return;
}

LL Dijkstra(int n)
{
	priority_queue<Node> pq;
	pq.push(Node(1, 0));
	dis[1] = 0;
	while(!pq.empty())
	{
		Node cur = pq.top();
		pq.pop();
		int u = cur.u;
		if(vis[u])
			continue;
		vis[u] = true;
		for(int i = head[u]; i != -1; i = e[i].nxt)
		{
			int v = e[i].v;
			int w = e[i].w;
			if(!vis[v] && dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				pq.push(Node(v, dis[v]));
			}
		}
	}
	LL ans = 0;
	rep(i, 1, n)
		ans += dis[i];
	return ans;
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int test;
	scanf("%d", &test);
	while(test--)
	{
		mem(e), mem(add);
		int n, road;
		scanf("%d%d", &n, &road);
		init(n);
		rep(i, 1, road)
		{
			scanf("%d%d%d", &add[i].u, &add[i].v, &add[i].w);
			addedge(add[i].u, add[i].v, add[i].w);
		}
		LL ans = Dijkstra(n);
		init(n);
		rep(i, 1, road)
			addedge(add[i].v, add[i].u, add[i].w);
		ans += Dijkstra(n);
		printf("%lld\n", ans);
	}
	return 0;
}