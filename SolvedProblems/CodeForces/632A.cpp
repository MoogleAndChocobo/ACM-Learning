#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cctype>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i >= b; --i)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sfd(a) scanf("%lf", &a)
#define pb(a) push_back(a)

int main()
{
#ifdef LOCAL
	//~ freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);
#endif

	int n, cost;
	scanf("%d%d", &n, &cost);
	LL ans = 0;
	char rec[100][100] = {0};
	rep(i, 1, n)
		sfs(rec[i]);
	LL cnt = 0;
	dow(i, n, 1)
	{
		if(!strcmp(rec[i], "halfplus"))
			cnt++;
		ans += cnt * cost;
		cnt *= 2;
	}
	printf("%lld\n", ans / 2);


	return  0;
}