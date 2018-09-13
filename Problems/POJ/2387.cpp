//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#include<vector>

using namespace std;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a, b) memset(a, b, sizeof(a))

struct Node
{
	int v, d;
	Node(int vv, int dd):v(vv), d(dd){}
	friend bool operator <(Node a, Node b)
	{
			return a.d > b.d;
	}
};

int dis[MAX];
vector<Node> e[MAX];

void init(void)
{
	mem(dis, INF);
	return;
}

void Dijkstra(int n, int st)
{
	dis[st] = 0;
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
	while(~scanf("%d%d", &road, &n))
	{
		init();
		rep(i, 0, n)
			e[i].clear();
		while(road--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			e[u].push_back(Node(v, w));
			e[v].push_back(Node(u, w));
		}
		Dijkstra(n, 1);
		printf("%d\n", dis[n]);
	}
	return 0;
}