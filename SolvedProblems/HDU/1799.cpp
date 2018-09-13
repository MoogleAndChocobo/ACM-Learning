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
#define sfi(a) scanf("%d", &a)

const int MAX = 2e3 + 10;
const LL MOD = 1007;

int ans[MAX][MAX];

void init()
{
	rep(i, 1, 2005)
	{
		ans[i][0] = 1;
		rep(j, 1, 2005)
		{
			ans[i][j] = (ans[i - 1][j - 1] + ans[i - 1][j]) % MOD;
		}
	}
}

int main()
{
	init();

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int m, n;
		scanf("%d%d", &m, &n);
		printf("%d\n", ans[n + 1][m]);
	}
	return 0;
}