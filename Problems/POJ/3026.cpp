//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX_PIC = 3 * 1e2 + 10;
const int MAX = 1e2 + 10;
const int INF = 0x3f3f3f3f;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

struct Point
{
	int x, y;
} alien[MAX];

int pic[MAX_PIC][MAX_PIC];
int vis[MAX_PIC][MAX_PIC];
int cnta, row, column;
char c;

struct Ufs
{
	int prt[MAX];

	void init(int n)
	{
		rep(1, n)
			prt[i] = i;
		return;
	}

	int findprt(int x)
	{
		while(x != prt[x])
			x = prt[x];
		return x;
	}

	bool unite(int x, int y)
	{
		int px = findprt(x);
		int py = findprt(y);
		prt[x] = prt[y] = prt[px] = prt[py] = min(px, py);
		return px != py;
	}
};

struct Kruskal
{
	struct Edge
	{
		int u, v, w;
		Edge(int uu, int vv, int ww):u(uu), v(vv), w(ww){}
		friend bool operator <(Edge a, Edge b)
		{
			return a.w < b.w;
		}
	};

	vector<Edge> e;
	Ufs u;

	void init(void)
	{
		e.clear();
	}

	void addedge(int u, int v, int w)
	{
		e.push_back(Edge(u, v, w));
	}

	int solve(int n)
	{
		u.init(n);
		int cnt = 0, ans = 0;
		int len = e.size();
		sort(e.begin(), e.end());
		rep(0, len - 1)
		{
			if(u.unite(e[i].u, e[i].v))
			{
				cnt++;
				ans += e[i].w;
			}
			if(cnt == n - 1)
				break;
		}
		return ans;
	}
} k;

bool check(int x, int y)
{
	if(!vis[x][y] && pic[x][y] && x >= 1 && x <= row && y >= 1 && y <= column)
		return true;
	return false;
}

void init(void)
{
	k.init();
	mst(alien);
	mst(pic);
	mst(vis);
	row = column = 0;
	cnta = 1;
	return;
}

void Bfs_Alien(int u, int x, int y)
{
	mst(vis);
	Point cur = {x, y};
	queue<Point> q;
	int cntfind = 1;
	
	q.push(cur);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		
		int tmpnum = pic[cur.x][cur.y];
		if(tmpnum != INF && tmpnum != u)
		{
			k.addedge(u, tmpnum, vis[cur.x][cur.y]);
			cntfind++;
		}
			
		if(cntfind == cnta)
			break;
			
		rep(0, 3)
		{
			Point now = cur;
			now.x += dir[i][0];
			now.y += dir[i][1];
			if(check(now.x, now.y))
			{
				q.push(now);
				vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
			}
		}
		vis[x][y] = 1;
	}
	return;
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
		init();
		scanf("%d%d", &column, &row);
		rep(1, row)
		{
			while(getchar() != '\n')
				;
			for(int j = 1; j <= column; j++)
			{
				c = getchar();
				if(c == 'S')
					pic[i][j] = 1, alien[1].x = i, alien[1].y = j;
				else if(c == 'A')
				{
					pic[i][j] = ++cnta;
					alien[cnta].x = i, alien[cnta].y = j;
				}
				else if(c == ' ')
					pic[i][j] = INF;
			}
		}

		rep(1, cnta)
			Bfs_Alien(i, alien[i].x, alien[i].y);

		printf("%d\n", k.solve(cnta));
	}
	return 0;
}