#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstring>
#include <cstdlib>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <deque>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned U;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", &a)
#define sfu(a) scanf("%llu", &a)
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()

const int MAX = 1e3 + 10;
const LL MOD = 998244353;

LL c[MAX][MAX];

void init()
{
	rep(i, 0, 1005)
	{
		c[i][0] = c[i][i] = 1;
		rep(j, 1, i - 1)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
}


LL s[MAX];
LL dp[MAX];

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin );
	//~ freopen("out.txt", "w", stdout);
#endif

	init();


	int n;
	while(~sfi(n))
	{
		LL ans = 0;
		rep(i, 0, n - 1)
			sfl(s[i]);
		
		dp[n] = 1;
		dow(i, n - 1, 0)
		{
			if(s[i] <= 0)
				continue;
			int now = i + s[i] + 1;
			while(now <= n)
			{
				dp[i] += (dp[now] * 1LL * c[now - i - 1][s[i]]) % MOD;
				dp[i] %= MOD;
				++now;
			}
		}
		
		//~ rep(i, 0, n - 1)
		//~ {
			//~ printf("dp[%d] = %lld\n", i, dp[i]);
		//~ }
		
		rep(i, 0, n - 1)
		{
			ans += dp[i];
			ans %= MOD;
		}
		
		printf("%lld\n", ans);
	}

	return 0;
}
