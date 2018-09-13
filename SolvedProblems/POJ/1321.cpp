#include<cstdio>
#include<cstring>

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX = 15;
bool pic[MAX][MAX];
bool vis[MAX]; 
int m, k, cnt, ans;

void init(void)
{
	mst(pic);
	mst(vis);
	cnt = ans = 0;
}

void Dfs(int row)
{
	if(cnt == k)
	{
		ans++;
		return;
	}
	if(row > m)
		return;
	FOR(i, 1, m)
	{
		if(!vis[i] && pic[row][i])
		{
			cnt++;
			vis[i] = 1;
			Dfs(row + 1);
			cnt--;
			vis[i] = 0;
			
		}
	}
	
	Dfs(row + 1);
}

int main()
{
	while(~scanf("%d%d", &m, &k) && (m + 1) && (k + 1))
	{
		init();
		FOR(i, 1, m)
		{
			getchar();
			for(int j = 1; j <= m; j++)
			{
				char c;
				scanf("%c", &c);
				if(c == '#')
					pic[i][j] = 1;
			}
		}
		Dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}