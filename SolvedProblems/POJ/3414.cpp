#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define mst(s) memset(s, 0, sizeof(s))

const int MAX = 1e3 + 10;
int pic[MAX][MAX] = {0};
int vis[MAX][MAX] = {0};
int a, b, sum;

struct Node
{
	int x, y;
	int opr, prex, prey;
};

bool check(int x, int y)
{
	if(pic[x][y] == 0)
		return true;
	else
		return false;
}

Node store[MAX][MAX];
Node road[MAX * MAX];

int Bfs(void)
{
	queue<Node> q;
	Node cur;
	cur.x = cur.y = 0;
	cur.opr = cur.prex = cur.prey = -1;
	pic[cur.x][cur.y] = 1;
	store[cur.x][cur.y] = cur;
	q.push(cur);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		//printf("%d: %d %d\n", vis[cur.x][cur.y], cur.x, cur.y);
		if(cur.x == sum || cur.y == sum)
		{
			int step = vis[cur.x][cur.y];
			ROF(i, step, 1)
			{
				road[i] = store[cur.x][cur.y];
				cur = store[cur.prex][cur.prey];
			}
			return step;
		}
		Node now = cur;
		now.opr = 11, now.x = a, now.prex = cur.x, now.prey = cur.y;
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
			pic[now.x][now.y] = 1;
			store[now.x][now.y] = now;
			//printf("11in:%d: %d %d\n", vis[now.x][now.y], now.x, now.y);
		}
		pic[now.x][now.y] = 1;

		now = cur;
		now.opr = 12, now.y = b, now.prex = cur.x, now.prey = cur.y;
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
			store[now.x][now.y] = now;
			//printf("12in:%d: %d %d\n", vis[now.x][now.y], now.x, now.y);
		}
		pic[now.x][now.y] = 1;

		now = cur;
		now.opr = 21, now.x = 0, now.prex = cur.x, now.prey = cur.y;
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
			pic[now.x][now.y] = 1;
			store[now.x][now.y] = now;
			//printf("21in:%d: %d %d\n", vis[now.x][now.y], now.x, now.y);
		}
		pic[now.x][now.y] = 1;

		now = cur;
		now.opr = 22, now.y = 0, now.prex = cur.x, now.prey = cur.y;
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
			pic[now.x][now.y] = 1;
			store[now.x][now.y] = now;
			//printf("22in:%d: %d %d\n", vis[now.x][now.y], now.x, now.y);
		}
		pic[now.x][now.y] = 1;

		now = cur;
		now.opr = 31, now.prex = cur.x, now.prey = cur.y;
		if(cur.y <= a - cur.x)
			now.x += cur.y, now.y = 0;
		else
			now.x = a, now.y = cur.y - (a - cur.x);
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
			pic[now.x][now.y] = 1;
			store[now.x][now.y] = now;
			//printf("31in:%d: %d %d\n", vis[now.x][now.y], now.x, now.y);
		}
		pic[now.x][now.y] = 1;

		now = cur;
		now.opr = 32, now.prex = cur.x, now.prey = cur.y;
		if(cur.x <= b - cur.y)
			now.y += cur.x, now.x = 0;
		else
			now.x = cur.x - (b - cur.y), now.y = b;
		if(check(now.x, now.y))
		{
			q.push(now);
			vis[now.x][now.y] = vis[cur.x][cur.y] + 1;
			pic[now.x][now.y] = 1;
			store[now.x][now.y] = now;
			//printf("32in:%d: %d %d\n", vis[now.x][now.y], now.x, now.y);
		}
		pic[now.x][now.y] = 1;
	}
	return -1;
}

int main()
{
	while(~scanf("%d%d%d", &a, &b, &sum))
	{
		mst(pic);
		mst(vis);
		int step = Bfs();
		if(step == -1)
			printf("impossible\n");
		else
		{
			printf("%d\n", step);
			FOR(i, 1, step)
			{
				//printf("%d %d\n", road[i].x, road[i].y);
				switch(road[i].opr)
				{
					case 11:printf("FILL(1)\n");
							break;
					case 12:printf("FILL(2)\n");
							break;
					case 21:printf("DROP(1)\n");
							break;
					case 22:printf("DROP(2)\n");
							break;
					case 31:printf("POUR(2,1)\n");
							break;
					case 32:printf("POUR(1,2)\n");
							break;
					default:printf("bug\n");
				}
			}
		}
	}
	return 0;
}