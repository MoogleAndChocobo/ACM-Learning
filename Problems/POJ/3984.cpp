#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)

typedef struct Point
{
	int prex, prey, x, y;
};

const int MAX = 50;
int pic[MAX][MAX] = {0};
int vis[MAX][MAX] = {0};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
Point store[MAX][MAX];
int road[MAX][2] = {0};
int m, n, sx, sy, dx, dy;

bool check(int x, int y)
{
	if(x >= 1 && x <= m && y >= 1 && y <= n && pic[x][y] == 0)
		return true;
	else
		return false;
}

int Bfs(void)
{
	Point cur;
	cur.x = 1, cur.y = 1;
	cur.prex = 0, cur.prey = 0;
	store[cur.x][cur.y] = cur;
	queue<Point> q;
	q.push(cur);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if(cur.x == dx && cur.y == dy)
		{
			int step = vis[cur.x][cur.y];
			Point tempdata;
			ROF(i, step, 1)
			{
				road[i][0] = cur.x - 1;
				road[i][1] = cur.y - 1;
				tempdata = store[cur.prex][cur.prey];
				cur = tempdata;
			}
			return step;
		}
		FOR(i, 0, 3)
		{
			Point now = cur;
			now.x += dir[i][0];
			now.y += dir[i][1];
			now.prex = cur.x;
			now.prey = cur.y;
			if(check(now.x, now.y))
			{
				store[now.x][now.y] = now;
				q.push(now);
				vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
				pic[now.x][now.y] = 1;
			}
		}
	}
	return 0;
}

int main()
{
	sx = sy = 1;
	dx = dy = m = n = 5;
	memset(vis, 0, sizeof(vis));
	FOR(i, 1, 5)
	{
		for(int j = 1; j <= 5 ; j++)
		{
			scanf("%1d", &pic[i][j]);
		}
	}
	int step = Bfs();
	printf("(0, 0)\n");
	FOR(i, 1, step)
	{
		printf("(%d, %d)\n", road[i][0], road[i][1]);
	}
	return 0;
}