//¿ÉÒÔ×ßKFC(£»¡ä¡Ð`))

#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

typedef struct Point
{
	int x, y;
	int step;
};

const int MAX = 2 * 1e2 + 10;
const int INF = 0x3f3f3f3f;

int pic[MAX][MAX] = {0};
int vis[MAX][MAX] = {0};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int m, n, ysx, ysy, msx, msy, ygetcnt, mgetcnt;
int endcnt;

Point yroad[MAX * MAX];
Point mroad[MAX * MAX];

void Bfs_y(void)
{
	ygetcnt = 0;
	memset(vis, 0, sizeof(vis));
	Point cur;
	cur.x = ysx, cur.y = ysy;
	queue<Point> q;
	q.push(cur);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if(pic[cur.x][cur.y] == 3)
		{
			bool flag = true;
			FOR(i, 0, ygetcnt - 1)
			{
				if(yroad[i].x == cur.x && yroad[i].y == cur.y)
				{
					flag = false;
					break;
				} 
			}
			if(flag)
			{
				yroad[ygetcnt].x = cur.x;
				yroad[ygetcnt].y = cur.y;
				yroad[ygetcnt++].step = vis[cur.x][cur.y];
				if(ygetcnt == endcnt)
					break;
			}
		}
		FOR(i, 0, 3)
		{
			Point now = cur;
			now.x += dir[i][0];
			now.y += dir[i][1];
			if(!vis[now.x][now.y] && (pic[now.x][now.y] == 1 || pic[now.x][now.y] == 3))
			{
				q.push(now);
				vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
			}
		}
	}
}

void Bfs_m(void)
{
	mgetcnt = 0;
	memset(vis, 0, sizeof(vis));
	Point cur;
	cur.x = msx, cur.y = msy;
	queue<Point> q;
	q.push(cur);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if(pic[cur.x][cur.y] == 3)
		{
			bool flag = true;
			FOR(i, 0, mgetcnt - 1)
			{
				if(mroad[i].x == cur.x && mroad[i].y == cur.y)
				{
					flag = false;
					continue;
				}
			}
			if(flag)
			{
				mroad[mgetcnt].x = cur.x;
				mroad[mgetcnt].y = cur.y;
				mroad[mgetcnt++].step = vis[cur.x][cur.y];
				if(mgetcnt == endcnt)
					break;
			}
		}
		FOR(i, 0, 3)
		{
			Point now = cur;
			now.x += dir[i][0];
			now.y += dir[i][1];
			if(!vis[now.x][now.y] && (pic[now.x][now.y] == 1 || pic[now.x][now.y] == 3))
			{
				q.push(now);
				vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
			}
		}
	}
}


int main()
{
	while(~scanf("%d%d", &m, &n))
	{
		getchar();
		if(!m && !n)
			break;
		memset(pic, 0, sizeof(pic));
		endcnt = 0;
		FOR(i, 1, m)
		{
			for(int j = 1; j <= n; j++)
			{
				char c;
				scanf("%c", &c);
				if(c == '.')
					pic[i][j] = 1;
				else if(c == 'Y')
					ysx = i, ysy = j;
				else if(c == 'M')
					msx = i, msy = j;
				else if(c == '@')
				{
					pic[i][j] = 3;
					endcnt++;
				}
			}
			getchar();
		}
		pic[ysx][ysy] = pic[msx][msy] = 0;
		
		Bfs_y(), Bfs_m();
		int mn = INF;
		for(int j = 0; j < ygetcnt; j++)
			for(int k = 0; k < mgetcnt; k++)
				if(yroad[j].x == mroad[k].x && yroad[j].y == mroad[k].y)
				{
					mn = min(mn, yroad[j].step + mroad[k].step);
					break;
				}
		printf("%d\n", mn * 11);
	}
	return 0;
}