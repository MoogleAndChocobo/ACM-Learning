#include <bits/stdc++.h>

using namespace std;

#define sfi(a) scanf("%d", &a)
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

typedef long long LL;

const int MAX = 1e5 + 10;
const int N = 1e5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int prime[MAX];
bool isprime[MAX];
int pcnt = 0;
bool vis[MAX];
int s[MAX], ans[MAX][5];

void init()
{
	mst(isprime, true);
	isprime[0] = isprime[1] = false;
	rep(i, 2, N)
	{
		if(isprime[i])
			prime[++pcnt] = i;
		for(int j = 1; j <= pcnt && i * prime[j] <= N; ++j)
		{
			isprime[i * prime[j]] = false;
			if(i % prime[j] == 0)
				break;
		}
	}
}

int main()
{
	init();
	int n;
	while(~sfi(n))
	{
		mem(vis), mem(ans), mem(s);
		vis[1] = true;
		rep(i, n / 2 + 1, n)
			if(isprime[i])
				vis[i] = true;
		int cnt = 0;
		rep(i, 3, n / 2)
		{
			if(isprime[i])
			{
				int tmpcnt = 0;
				for(int j = i; j <= n; j += i)
					if(!vis[j])
					{
						s[tmpcnt++] = j;
						vis[j] = true;
					}
				swap(s[0], s[1]);
				if(tmpcnt % 2)
					vis[2 * i] = false;
				for(int j = tmpcnt % 2; j < tmpcnt; j += 2)
					ans[cnt][0] = s[j], ans[cnt++][1] = s[j + 1];
			}
		}
		int tmpcnt = 0;
		rep(i, 1, n)
			if(!vis[i])
				s[tmpcnt++] = i;
		for(int i = 0; i + 1 < tmpcnt; i += 2)
			ans[cnt][0] = s[i], ans[cnt++][1] = s[i + 1];
		printf("%d\n", cnt);
		rep(i, 0, cnt - 1)
			printf("%d %d\n", ans[i][0], ans[i][1]);
	}
	return 0;
}