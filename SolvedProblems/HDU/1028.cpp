#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)

const int MAX = 1e3 + 5;

struct GeneratingFunction
{
	LL pre[MAX], now[MAX], ans[MAX];

	void init(int N)
	{
		mem(pre), mem(now);
		rep(i, 0, N)
			pre[i] = 1;

		rep(i, 2, N)
		{
			rep(j, 0, N)
			{
				for(int k = 0; j + k <= N; k += i)
				{
					now[j + k] += pre[j];
				}
			}
			rep(j, 0, N)
				pre[j] = now[j], now[j] = 0;
		}
	}

	LL solve(int n)
	{
		return pre[n];
	}
};

int main()
{
	GeneratingFunction g;
	g.init(125);
	int n;
	while(~sfi(n))
	{
		printf("%lld\n", g.solve(n));
	}

	return 0;
}