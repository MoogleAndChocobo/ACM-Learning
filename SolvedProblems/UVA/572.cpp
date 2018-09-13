#include<cstdio>
#include<cstring>

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX = 1e2 + 10;
int pic[MAX][MAX];
int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
int m, n, cnt;

void init(void)
{
	mst(pic);
	cnt = 0;
}

void Dfs(int x, int y)
{
	FOR(i, 0, 7)
	{
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(pic[tx][ty])
		{
			pic[tx][ty] = 0;
			Dfs(tx, ty);
		}
	}
	return;
}

int main()
{
	while(~scanf("%d%d", &m, &n) && m && n)
	{
		init();
		FOR(i, 1, m)
		{
			getchar();
			for(int j = 1; j <= n; j++)
			{
				char c;
				scanf("%c", &c);
				if(c == '@')
					pic[i][j] = 1;
			}
		}

		FOR(i, 1, m)
			for(int j = 1; j <= n; j++)
			{
				if(pic[i][j])
				{
					pic[i][j] = 0;
					cnt++;
					Dfs(i, j);
				}
			}
		printf("%d\n", cnt);
	}
	return 0;
}