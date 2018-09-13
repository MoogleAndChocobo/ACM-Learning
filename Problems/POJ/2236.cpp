#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAX = 1e3 + 10;
const int MAXSIZE = 5;

#define rep(a, b) for(int i = a; i <= b; i++)

int prt[MAX];
int re[MAX];
int g[MAX][MAX];
int cnt;

struct Point
{
	double x, y;
} s[MAX];

void init(int n)
{
	rep(1, n)
		prt[i] = i;
	return;
}

int findprt(int x)
{
	while(x != prt[x])
		x = prt[x];
	return x;
}

bool check(int x, int y)
{
	return findprt(x) == findprt(y);
}

void unite(int x, int y)
{
	int px = findprt(x);
	int py = findprt(y);
	prt[x] = prt[y] = prt[px] = prt[py]= min(px, py);
	return;
}

int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	init(n);
	
	rep(1, n)
		scanf("%lf%lf", &s[i].x, &s[i].y);
	rep(1, n)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j < i)
			{
				double tmp = sqrt((s[i].x - s[j].x) * (s[i].x - s[j].x) + (s[i].y - s[j].y) * (s[i].y - s[j].y));
				if(tmp > 1.0 * d)
					g[i][j] = g[j][i] = false;
				else
					g[i][j] = g[j][i] = true;
			}
		}
	}
	
	char opr[MAXSIZE] = {0};
	while(~scanf("%s", opr))
	{
		if(opr[0] == 'S')
		{
			int p, q;
			scanf("%d%d", &p, &q);
			if(check(p, q))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
		else if(opr[0] == 'O')
		{
			int x;
			scanf("%d", &x);
			rep(1, n)
			{
				for(int j = 0; j < cnt; j++)
				{
					if(g[x][re[j]])
						unite(x, re[j]);
				}
			}
			re[cnt++] = x;
		}
	}
	return 0;
}