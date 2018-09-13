//~ #define LOCAL

#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int MAX = 2e2 + 10;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a, b) memset(a, b, sizeof(a))

struct Point
{
	int x, y;
} rec[MAX];;

struct Edge
{
	int v;
	double w;
	Edge(int vv, double ww):v(vv), w(ww){}
	friend bool operator <(Edge a, Edge b)
	{
		return a.w > b.w;
	}
};

vector<Edge> e[MAX];
double dis[MAX];
int cnt;

void Dijkstra(int n, int st, int en)
{
	dis[st] = 0;
	priority_queue<Edge> pq;
	pq.push(Edge(st, dis[st]));
	while(!pq.empty())
	{
		Edge cur = pq.top();
		pq.pop();
		int len = (int)e[cur.v].size();
		rep(i, 0, len - 1)
		{
			Edge now = e[cur.v][i];
			if(dis[now.v] > max(now.w, cur.w))
			{
				dis[now.v] = max(now.w, cur.w);
				pq.push(Edge(now.v, dis[now.v]));
			}
		}
	}
	return;
}

void init(int n)
{
	rep(i, 1, n)
		dis[i] = INF;
	rep(i, 1, n)
		e[i].clear();
	return;
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif //LOCAL

	int n;
	while(scanf("%d", &n) == 1 && n)
	{
		init(n);
		rep(i, 1, n)
		{
			scanf("%d%d", &rec[i].x, &rec[i].y);
		}

		rep(i, 1, n - 1)
		{
			rep(j, i + 1, n)
			{
				double l = sqrt((double)(rec[i].x - rec[j].x) * (rec[i].x - rec[j].x) + (double)(rec[i].y - rec[j].y) * (rec[i].y - rec[j].y));
				e[i].push_back(Edge(j, l));
				e[j].push_back(Edge(i, l));
			}
		}
		Dijkstra(n, 1, 2);
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++cnt, dis[2]);
	}
	return 0;
}