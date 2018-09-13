//~ #define LOCAL

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<cctype>
#include<vector>
#include<set>
#include<queue>

using namespace std;

typedef long long LL;

const int MAX = 1e5 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int v[N] = {0,150,200,350};
	int w[N] = {0,150,200,350};
	int dp[MAX] = {0};

	int T;
	sfi(T);
	rep(i, 1, T)
	{
		int total;
		sfi(total);
		mem(dp);
		rep(i, 1, 3)
		{
			for(int j = w[i]; j <= total; j++)
			{
				dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
			}
		}
		printf("%d\n", total - dp[total]);
	}
	return 0;
}