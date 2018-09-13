#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define rep(a, b) for(int i = a; i <= b; i++)
#define mst(a) memset(a, 0, sizeof(a))

const int MAX = 1e2 + 10;
int a[MAX], check[MAX], ans[MAX];
int store[MAX][MAX];
int m, n, mx;

void GetTmpAns(void)
{
	int tmpsum = 0;
	rep(1, n)
	{
		if(check[i])
		{
			for(int j = 1; j <= n; j++)
			{
				if(!check[j])
					tmpsum += store[i][j];
			}
		}
	}
	mx = max(mx, tmpsum);
	mst(check);
	return;
}

void Dfs(int id, int cnt)
{
	if(cnt == m)
	{
		rep(0, m - 1)
			check[ans[i]] = 1;
		GetTmpAns();
		return;
	}
	rep(id, n - 1)
	{
		ans[cnt] = a[i];
		Dfs(i + 1, cnt + 1);
	}
	return;
}

int main()
{
	rep(0, 50)
	{
		a[i] = i + 1;
	}
	while(~scanf("%d", &n))
	{
		rep(1, n)
			for(int j = 1; j <= n; j++)
				scanf("%d", &store[i][j]);
		mx = 0;
		rep(1, n / 2)
		{
			m = i;
			mst(ans);
			Dfs(0,0);
		}
		printf("%d\n", mx);
	}
	return 0;
}