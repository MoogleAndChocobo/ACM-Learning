#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

struct Point
{
	int x, y, lmt, flag;
};

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int m, n, jsx, jsy;
int vis[MAX][MAX];
Point pic[MAX][MAX];

queue<Point> q;
queue<Point> joeq;

void init()
{
	while(!q.empty())
		q.pop();
	while(!joeq.empty())
		joeq.pop();
	mst(pic);
	mst(vis);
	m = n = jsx = jsy = 0;
}

void Bfs_Init(void)
{
	mst(vis);
	
	return;
}

bool check(int x, int y)
{
	if(!vis[x][y] && x >= 1 && x <= m && y >= 1 && y <= n && pic[x][y].flag)
		return true;
	return false;
}

bool IsAns(int x, int y)
{
	if(x == 1 || x == m || y == 1 || y == n)
		return true;
	return false;
}

bool CanPass(int prex, int prey, int x, int y)
{
	if(vis[prex][prey] + 1 < pic[x][y].lmt && check(x, y))
		return true;
	return false;
}

void Bfs_Fire()
{
	Bfs_Init();

	while(!q.empty())
	{
		Point cur = q.front();
		q.pop();
		rep(0, 3)
		{
			Point now = cur;
			now.x += dir[i][0];
			now.y += dir[i][1];
			if(check(now.x, now.y))
			{
				q.push(now);
				vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
				pic[now.x][now.y].lmt = vis[now.x][now.y];
			}
		}
	}
	return;
}

int Bfs_Joe(void)
{
	Bfs_Init();
	
	Point cur;
	cur.x = jsx, cur.y = jsy;
	joeq.push(cur);
	while(!joeq.empty())
	{
		cur = joeq.front();
		joeq.pop();
		rep(0, 3)
		{
			Point now = cur;
			now.x += dir[i][0];
			now.y += dir[i][1];
			if(CanPass(cur.x, cur.y, now.x, now.y))
			{
				vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
				if(IsAns(now.x, now.y))
					return vis[now.x][now.y] + 1;
				joeq.push(now);
			}
		}
	}
	return -1;
}

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		init();
		
		scanf("%d%d", &m, &n);
		rep(1, m)
		{
			getchar();
			for(int j = 1; j <= n; j++)
			{
				pic[i][j].x = i, pic[i][j].y = j;
				char c;
				scanf("%c", &c);
				if(c == '.')
					pic[i][j].lmt = INF, pic[i][j].flag = 1;
				else if(c == 'J')
					pic[i][j].lmt = INF, pic[i][j].flag = 1, jsx = i, jsy = j;
				else if(c == 'F')
					pic[i][j].lmt = pic[i][j].flag = 0, q.push(pic[i][j]);
				else
					pic[i][j].flag = pic[i][j].lmt = 0;
			}
		}
		
		if(jsx == 0 && jsy == 0)
			printf("IMPOSSIBLE");
		else if(IsAns(jsx, jsy))
			printf("1");
		else
		{
			Bfs_Fire();
			int step = Bfs_Joe();
			if(step == -1)
				printf("IMPOSSIBLE");
			else
				printf("%d", step);
		}
		printf("\n");
	}
	return 0;
}
