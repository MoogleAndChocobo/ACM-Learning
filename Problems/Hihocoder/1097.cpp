//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))

int g[MAX][MAX];

int Prim(int n)
{
	int d[MAX] = {0}, prt[MAX] = {0};
	bool vis[MAX] = {0};

	rep(i, 1, n)
	{
		d[i] = INF;
		prt[i] = 0;
	}

	d[1] = 0;

	while(true)
	{
		int mncost = INF, idx = 0;
		rep(i, 1, n)
		{
			if(!vis[i] && d[i] < mncost)
			{
				mncost = d[i];
				idx = i;
			}
		}
		if(!idx)
			break;
		vis[idx] = true;

		rep(i, 1, n)
		{
			if(!vis[i])
			{
				if(g[idx][i] < d[i])
				{
					d[i] = g[idx][i];
					prt[i] = idx;
				}
			}
		}
	}

	int sum = 0;
	rep(i, 1, n)
	{
		if(prt[i])
		{
			sum += g[i][prt[i]];
		}
	}
	return sum;
}

void init(int n)
{
	mem(g);
	return;
}

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int n;
	while(~scanf("%d", &n))
	{
		rep(i, 1, n)
		{
			rep(j, 1, n)
			{
				scanf("%d", &g[i][j]);
			}
		}
	}
	printf("%d\n", Prim(n));
	return 0;
}
