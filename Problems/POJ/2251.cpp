#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 50;
int m, n, p, sx, sy, sz, dx, dy, dz;
int pic[MAX][MAX][MAX] = {0};
int vis[MAX][MAX][MAX] = {0};
int dir[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

typedef struct
{
	int x, y, z;
} Point;

bool check(int x, int y, int z)
{
	if(pic[x][y][z])
		return true;
	else
		return false;
}

int Bfs(void)
{
	queue<Point> q;
	Point cur;
	cur.x = sx, cur.y = sy, cur.z = sz;
	q.push(cur);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if(cur.x == dx && cur.y == dy && cur.z == dz)
			return vis[cur.x][cur.y][cur.z];
		FOR(i, 0, 5)
		{
			Point nxt = cur;
			nxt.x += dir[i][0];
			nxt.y += dir[i][1];
			nxt.z += dir[i][2];
			if(check(nxt.x, nxt.y, nxt.z))
			{
				q.push(nxt);
				vis[nxt.x][nxt.y][nxt.z] = vis[cur.x][cur.y][cur.z] + 1;
				pic[nxt.x][nxt.y][nxt.z] = 0;
			}
		}
	}
	return 0;
}

int main()
{
	while(~scanf("%d%d%d", &m, &n, &p))
	{
		getchar();
		if(m == 0 && n == 0 && p == 0)
			break;
		memset(vis, 0, sizeof(vis));
		FOR(i, 1, m)
		{
			for(int j = 1; j <= n; j++)
			{
				for(int k = 1; k <= p; k++)
				{
					char c;
					scanf("%c", &c);
					if(c == '.')
						pic[i][j][k] = 1;
					else if(c == 'S')
						sx = i, sy = j, sz = k;
					else if(c == 'E')
						dx = i, dy = j, dz = k, pic[i][j][k] = 1;
				}
				getchar();
			}
			getchar();
		}
		int step = Bfs();
		if(step)
			printf("Escaped in %d minute(s).\n", step);
		else
			printf("Trapped!\n");
	}
	return 0;
}