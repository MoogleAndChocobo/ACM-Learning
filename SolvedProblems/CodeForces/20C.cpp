//~ #define LOCAL

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX = 1e5 + 10;
const LL INF = 0x3f3f3f3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a, b) memset(a, b, sizeof(a))

struct Node
{
	int v;
	LL d;
	Node(int vv, LL dd):v(vv), d(dd){}
	friend bool operator <(Node a, Node b)
	{
			return a.d > b.d;
	}
};

int prt[MAX];
LL dis[MAX];
int rec[MAX];
vector<Node> e[MAX];

void init(int n)
{
	rep(i, 1, n)
		dis[i] = INF;
	mem(prt, 0);
	mem(rec, 0);
	return;
}

void Dijkstra(int n, int st)
{
	dis[st] = 0;
	prt[st] = -1;
	priority_queue<Node> pq;
	pq.push(Node(st, dis[st]));
	while(!pq.empty())
	{
		Node cur = pq.top();
		pq.pop();
		rep(i, 0, (int)e[cur.v].size() - 1)
		{
			Node now = e[cur.v][i];
			if(dis[now.v] > cur.d + now.d)
			{
				dis[now.v] = cur.d + now.d;
				prt[now.v] = cur.v;
				pq.push(Node(now.v, dis[now.v]));
			}
		}
	}
	return;
}

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int road, n;
	while(~scanf("%d%d", &n, &road))
	{
		init(n);
		rep(i, 0, n)
			e[i].clear();
		while(road--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			e[u].push_back(Node(v, (LL)w));
			e[v].push_back(Node(u, (LL)w));
		}
		Dijkstra(n, 1);
		if(dis[n] == INF)
		{
			printf("-1\n");
			continue;
		}
		int cnt = 0, x = n;
		while(prt[x] != -1)
		{
			rec[cnt++] = x;
			x = prt[x];
		}
		rec[cnt] = 1;
		dow(i, cnt, 0)
		{
			printf("%d", rec[i]);
			if(i)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}