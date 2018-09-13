//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<map>
#include<functional>

using namespace std;

typedef long long LL;

const int MAX = 1e3 + 10;
const int dirnd[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

#define sfi(a) scanf("%d", &a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

bool pic[MAX][MAX];
int vis[MAX][MAX];
int m, n, sx, sy, ex, ey, lmt;

struct Point
{
	int x, y, opr, cnt;
	Point(int xx = 0, int yy = 0, int oo = 0, int cc = 0):x(xx), y(yy), opr(oo), cnt(cc){}
	friend bool operator <(Point a, Point b)
	{
		return a.cnt > b.cnt;
	}
};

bool check(Point &a)
{
	if(a.cnt > lmt || a.x < 1 || a.x > m || a.y < 1 || a.y > n || !pic[a.x][a.y])
		return false;
	if(!vis[a.x][a.y] || vis[a.x][a.y] >= a.cnt)
		return true;
	return false;
}

void init(void)
{
	mem(pic), mem(vis);
	return;
}

bool Bfs(void)
{
	if(!pic[ex][ey])
		return false;
	priority_queue<Point> pq;
	pq.push(Point(sx, sy, -1, 0));
	vis[sx][sy] = 1;
	while(!pq.empty())
	{
		Point cur = pq.top();
		pq.pop();
		if(cur.x == ex && cur.y == ey)
			return true;
		rep(i, 0, 3)
		{
			Point now = cur;
			now.x += dirnd[i][0];
			now.y += dirnd[i][1];
			now.opr = i;
			if(i != cur.opr && cur.opr != -1)
				now.cnt++;
			if(check(now))
			{
				if(now.x == ex && now.y == ey)
					return true;
				pq.push(now);
				vis[now.x][now.y] = now.cnt;
			}
		}
	}
	return false;
}

int main()
{

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif	//LOCAL

	int T;
	while(~sfi(T))
	{
		rep(i, 1, T)
		{
			init();
			scanf("%d%d", &m, &n);
			rep(i, 1, m)
			{
				getchar();
				rep(j, 1, n)
				{
					char c;
					c = getchar();
					if(c == '.')
						pic[i][j] = true;
				}
			}
			scanf("%d%d%d%d%d", &lmt, &sy, &sx, &ey, &ex);
			printf("%s\n", Bfs() ? "yes" : "no");
		}
	}
	return 0;
}