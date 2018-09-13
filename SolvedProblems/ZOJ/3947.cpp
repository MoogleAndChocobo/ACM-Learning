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
	int T;
	sfi(T);
	while(T--)
	{
		int n;
		sfi(n);
		LL sum = (LL)n;
		rep(i, 1, n)
		{
			LL tmp;
			sfl(tmp);
			sum += tmp;
		}
		printf("%lld\n", sum);
	}
	return 0;
}