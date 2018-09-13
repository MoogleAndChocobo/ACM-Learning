#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

const int MAX = 1e5 + 5;
const LL MOD = 1e9 + 7;

LL a[MAX], b[MAX], dis[MAX];
vector<int> out[MAX];
int in[MAX], len[MAX];
bool vis[MAX];
LL ans = 0;

inline LL inl()
{
	char c=getchar();
	while(!isdigit(c))c=getchar();
	LL x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

inline int inr()
{
	char c=getchar();
	while(!isdigit(c))c=getchar();
	int x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void init(int n)
{
	rep(i, 1, n)
		out[i].clear();
	mem(a), mem(b), mem(in), mem(len), mem(vis);
	mst(dis, -1);
	ans = 0;
}

LL dfs(int cur)
{
	vis[cur] = true;

	if(dis[cur] != -1)
		return dis[cur];
	if(!len[cur])
		return b[cur];

	LL now = 0;
	rep(i, 0, len[cur] - 1)
	{
		vis[out[cur][i]] = true;
		LL tmp = dfs(out[cur][i]);
		ans += (a[cur] * (tmp % MOD))% MOD;
		ans %= MOD;
		now += tmp;
		now %= MOD;
	}
	dis[cur] = (now + b[cur]) % MOD;
	return dis[cur];
}

int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		init(n);
		rep(i, 1, n)
			a[i] = inl(), b[i] = inl();

		rep(i, 1, m)
		{
			int u, v;
			u = inr(), v = inr();
			out[u].push_back(v);
			in[v]++;
		}

		vector<int> idx;
		rep(i, 1, n)
		{
			if(!in[i])
				idx.push_back(i);
			len[i] = out[i].size();
		}

		int length = idx.size();
		rep(i, 0, length - 1)
		{
			if(!vis[idx[i]])
				dfs(idx[i]);
		}

		printf("%lld\n", ans);
	}
	return 0;
}
