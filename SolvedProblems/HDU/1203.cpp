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

const int MAX = 1e5 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%ld", &a)
#define sfs(a) scanf("%s", a)
#define sfc(a) getchar(a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))

int main()
{
	
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int sum, n;
	while(scanf("%d%d", &sum, &n) == 2 && !(!sum && !n))
	{
		int cost[MAX] = {0};
		double rate[MAX] = {0};
		double dp[MAX] = {0};
		rep(i, 0, sum)
		{
			dp[i] = 1;
		}
		rep(i, 1, n)
		{
			scanf("%d%lf", &cost[i], &rate[i]);
		}
		rep(i, 1, n)
		{
			dow(j, sum, cost[i])
			{
				dp[j] = min(dp[j], dp[j - cost[i]] * (1 - rate[i]));
			}
		}
		printf("%.1lf%%\n", (1 - dp[sum]) * 100);
	}

	return 0;
}