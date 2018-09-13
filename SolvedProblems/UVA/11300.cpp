//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
#include<cctype>
#include<functional>
#include<ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LF;

const int MAX = 1e6 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfu(a) scanf("%llu", &a)
#define sfd(a) scanf("%ld", &a)
#define sfs(a) scanf("%s", a)
#define sfc(a) getchar(a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))

LL dp[MAX];
LL s[MAX];

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int n;
	while(~sfi(n) && n)
	{
		mem(dp), mem(s);
		LL sum = 0;
		rep(i, 1, n)
		{
			sfl(s[i]);
			sum += s[i];
		}
		sum /= n;
		rep(i, 1, n - 1)
		{
			dp[i] = dp[i - 1] + s[i] - sum;
		}
		sort(dp, dp + n);
		LL tmp = dp[n / 2];
		LL ans = 0;
		rep(i, 0, n - 1)
		{
			ans += fabs(tmp - dp[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}