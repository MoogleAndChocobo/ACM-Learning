#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<cctype>
#include<cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned U;

const int MAX = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const int N = 1e2;
const int MOD = 1e9 + 7;
const LL LINF = 0x3f3f3f3f3f3f3f;
const LL LMT = 3 * N + 10;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)

int getcnt(int n)
{
	int cnt = 1;
	while(n != 1)
	{
		cnt++;
		if(n & 1)
			n = 3 * n + 1;
		else
			n /= 2;
	}
	return cnt;
}

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	int m, n;
	while(~scanf("%d%d", &m, &n))
	{
		bool flag = m <= n;
		if(!flag)
			swap(m, n);
		int ans = 0;
		rep(i, m, n)
		{
			ans = max(ans, getcnt(i));
		}
		if(flag)
			printf("%d %d %d\n", m, n, ans);
		else
			printf("%d %d %d\n", n, m, ans);
	}
	return 0;
}