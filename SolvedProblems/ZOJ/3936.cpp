#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)

const int MAX = 2e3 + 5;
const int N = 1e5 + 4;
const LL INIT = 0x3f3f3f3f3f3f3f3f;

LL w[MAX];
LL dp[MAX][MAX];

bool cmp(LL a, LL b)
{
	return a > b;
}

int main()
{
	int n;
	while(~sfi(n))
	{
		rep(i, 1, n)
		{
			int a, b, p, q;
			scanf("%d%d%d%d", &a, &b, &p, &q);
			printf("%d %d\n%d %d\n", p, b + q, a, b + q);
		}
	}
	return 0;
}