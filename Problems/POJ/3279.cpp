#include<cstdio>
#include<cstring>

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 20;
int pic[MAX][MAX];
int ans[MAX][MAX];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int m, n;

void change(int x, int y)
{
	pic[x][y] = !pic[x][y];
	ans[x][y] = !ans[x][y];
	FOR(i, 0, 3)
	{
		int nowx = x + dir[i][0];
		int nowy = y + dir[i][1];
		if(nowx >= 0 && nowy >= 0 && nowx < n && nowy < m)
			pic[nowx][nowy] = !pic[nowx][nowy];
	}
}
bool solve()
{
	int k = 1<<m;
	FOR(i, 0, k - 1)
	{
		int pos = i;
		for(int j = 0; j < m; j++, pos>>=1)
			if(pos&1)
				change(0, j);
		for(int j = 1; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				if(pic[j - 1][k])
					change(j, k);
			}
		}
		bool flag = false;
		for(int j = 0; j < m; j++)
			flag = flag | pic[n - 1][j];
		if(flag)
		{
			for(int j = 0; j < n; j++)
				for(int k = 0; k < m; k++)
					if(ans[j][k])
						change(j, k);
		}
		else
			return true;
	}
	return false;
}
int main()
{
	while(~scanf("%d%d", &n, &m))
	{
		FOR(i, 0, n - 1)
			for(int j = 0; j < m; j++)
				scanf("%d", &pic[i][j]);
		if(solve())
		{
			FOR(i, 0, n - 1)
			{
				for(int j = 0; j < m; j++)
				{
					printf("%d", ans[i][j]);
					if(j != m - 1)
						printf(" ");
					else
						printf("\n");
				}
			}
		}
		else printf("IMPOSSIBLE\n");
	}
}