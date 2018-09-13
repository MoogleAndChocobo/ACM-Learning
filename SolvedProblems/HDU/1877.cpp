#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cctype>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int MAX = 1e5 + 10;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define dow(i, a, b) for(int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf", &a)
#define sfs(a) scanf("%s", a)


int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
#endif	//LOCAL

	LL m;
	while(~sfl(m) && m)
	{
		LL a, b;
		scanf("%lld%lld", &a, &b);
		LL c = a + b;
		if(!c)
		{
			puts("0");
			continue;
		}
		int cnt = 0, ans[MAX] = {0};
		while(c)
		{
			ans[++cnt] = c % m;
			c /= m;
		}
		dow(i, cnt, 1)
			printf("%d", ans[i]);
		putchar('\n');
	}
	return 0;
}