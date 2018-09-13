#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int MAX = 1e2 + 10;
int pic[MAX][MAX] = {0};
int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,-1},{1,1},{-1,1},{-1,-1}};
int m, n;

void Dfs(int x, int y)
{
	int tx, ty;
	FOR(i, 0, 7)
	{
		tx = x + dir[i][0];
		ty = y + dir[i][1];
		if(pic[tx][ty])
		{
			pic[tx][ty] = 0;
			Dfs(tx, ty);
		}
	}
}

int main()
{
	while(~scanf("%d%d", &m, &n))
	{
		getchar();
		if(m == 0 && n == 0)
			break;
		int sum = 0;
		char c;
		FOR(i, 1, m)
		{
			for(int j = 1; j <= n; j++)
			{
				scanf("%c", &c);
				if(c == '*')
					pic[i][j] = 0;
				else if(c == '@')
					pic[i][j] = 1;
			}
			getchar();
		}
		FOR(i, 1, m)
		{
			for(int j = 1; j <= n; j++)
			{
				if(pic[i][j])
				{
					sum++;
					pic[i][j] = 0;
					Dfs(i, j);
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}