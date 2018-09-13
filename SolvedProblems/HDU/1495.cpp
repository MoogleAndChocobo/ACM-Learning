#include<bits/stdc++.h>

using namespace std;

#define mst(a) memset(a, 0, sizeof(a))

struct Node
{
	int x, y;
};

const int MAX = 1e2 + 10;
bool pic[MAX][MAX] = {0};
int vis[MAX][MAX] = {0};
int sum, m, n;

queue<Node> q;

bool check(int x, int y)
{
	if(pic[x][y] == 0)
		return true;
	return false;
}

int Bfs(void)
{
	while(!q.empty())
		q.pop();
	
	mst(vis);
	mst(pic);
	Node cur;
	cur.x = sum, cur.y = 0;
	q.push(cur);
	pic[cur.x][cur.y] = 1;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if((cur.x == sum / 2 && cur.y == sum / 2) || (cur.x == sum / 2 && !cur.y) || (!cur.x && cur.y == sum / 2))
			return vis[cur.x][cur.y];

		int z = sum - cur.x - cur.y;

		//printf("%d %d %d\n", cur.x, cur.y, z);
		//a->b
		Node now = cur;
		if(now.x <= m - now.y)
			now.x = 0, now.y += cur.x;
		else
			now.x -= m - cur.y, now.y = m;
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
		}
		pic[now.x][now.y] = 1;

		//a->c
		now = cur;
		if(now.x <= n - z)
			now.x = 0;
		else
			now.x -= n - z;
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
		}
		pic[now.x][now.y] = 1;

		//c->b
		now = cur;
		if(z <= m - now.y)
			now.y += z;
		else
			now.y = m;
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
		}
		pic[now.x][now.y] = 1;

		//b->c
		now = cur;
		if(now.y <= n - z)
			now.y = 0;
		else
			now.y -= n - z;
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
		}
		pic[now.x][now.y] = 1;

		//b->a
		now = cur;
		now.x += now.y, now.y = 0;
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
		}
		pic[now.x][now.y] = 1;

		//c->a
		now = cur;
		now.x += z;
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
		}
		pic[now.x][now.y] = 1;
	}
	return -1;
}

int main()
{
	while(~scanf("%d%d%d", &sum, &m, &n))
	{
		if(!sum && !m && !n)
			break;
		if(sum % 2)
		{
			printf("NO\n");
			continue;
		}
		int step = Bfs();
		if(step == -1)
			printf("NO\n");
		else
			printf("%d\n", step);
	}
	return 0;
}