#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)

const int MAX = 2e3 + 5;
const int N = 1e5 + 4;
const LL INIT = 0x3f3f3f3f3f3f3f3f;

struct edge{
	ll v, w, c;
	int next;
	edge(ll a = 0, ll b = 0, ll cc = 0, int nn = 0) {
		v = a, w = b, c = cc, next = nn;
	}
};

int n, m, cnt;
edge e[N << 1];
ll dis[N];
ll cst[N];
int head[N];
int vis[N];

void init()
{
	cnt = 0;
	memset(head, -1, sizeof head);
}

void addedge(int u, int v, ll w, ll c)
{
	e[cnt] = edge(v, w, c, head[u]); head[u] = cnt++;
	e[cnt] = edge(u, w, c, head[v]); head[v] = cnt++;
}

struct node {
	ll w, c, idx;
	node(ll w_ = 0, ll c_ = 0, ll id = 0) {
		w = w_, c = c_, idx = id;
	}
	
	bool operator< (const node& b)const{
		if (w == b.w)
			return c > b.c;
		return w > b.w;
	}
	
};

void dijkstra()
{
	priority_queue<node> q;
	
	for (int i = 0; i < n; i++)
		dis[i] = 9223372036854775807, cst[i] = 9223372036854775807, vis[i] = 0;
	
	dis[0] = cst[0] = 0;
	q.push(node(0, 0, 0));
	while (!q.empty()) {
		int u = q.top().idx;
		q.pop();
		
		if (vis[u]) continue;
		vis[u] = 1;
		
		for (int i = head[u]; i != -1; i = e[i].next){
			const ll v = e[i].v, w = e[i].w, c = e[i].c;
			if (vis[v]) continue;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				cst[v] = c;
				q.push(node(dis[v], cst[v], v));
			}
			else if (dis[v] == dis[u] + w && cst[v] > c) {
				cst[v] = c;
				q.push(node(dis[v], cst[v], v));
			}
		}
	}
	
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d%d", &n, &m);
		while (m--) {
			int u, v, w, c;
			scanf("%d%d%d%d", &u, &v, &w, &c);
			addedge(u, v, w, c);
		}
		
		dijkstra();
		ll cost = 0, dist = 0;
		for (int i = 0; i < n; i++)
			cost += cst[i], dist += dis[i];
		printf("%lld %lld\n", dist, cost);
	}
	return 0;
}
