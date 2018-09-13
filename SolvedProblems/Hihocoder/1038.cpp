#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)

const int MAX = 1e3 + 5;
const int N = 1e5 + 4;

struct Reward
{
	int v, w;
};

int main()
{
	int n, sum;
	while(~scanf("%d%d", &n, &sum))
	{
		Reward re[MAX];
		
		rep(i, 1, n)
			scanf("%d%d", &re[i].w, &re[i].v);
		
		int dp[N] = {0};
		rep(i, 1, n)
			dow(j, sum, re[i].w)
					dp[j] = max(dp[j], dp[j - re[i].w] + re[i].v);
		printf("%d\n", dp[sum]);
	}
	return 0;
}
