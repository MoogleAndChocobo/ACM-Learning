#include<cstdio>
#include<cstring>

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX = 25;
int pic[MAX][MAX];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int m, n, cnt, sx, sy;

void init(void)
{
	mst(pic);
	cnt = 1;
}

void Dfs(int x, int y)
{
	FOR(i, 0, 3)
	{
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(pic[tx][ty])
		{
			pic[tx][ty] = 0;
			cnt++;
			Dfs(tx, ty);
		}
	}
	return;
}

int main()
{
	while(~scanf("%d%d", &n, &m) && m && n)
	{
		init();
		FOR(i, 1, m)
		{
			getchar();
			for(int j = 1; j <= n; j++)
			{
				char c;
				scanf("%c", &c);
				if(c == '.')
					pic[i][j] = 1;
				else if(c == '@')
					sx = i, sy = j;
			}
		}

		Dfs(sx, sy);
		printf("%d\n", cnt);
	}
	return 0;
}